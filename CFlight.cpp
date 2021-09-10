#include "Flight.h"
#include "Host.h"
#include "Pilot.h"
#include "FlightCompException.h"

CFlight::CFlight(CFlightInfo &flightInfo) {
    this->flightInfo = new CFlightInfo(flightInfo);
    this->plane = NULL;
    this->crewMembers = new CCrewMember*[MAX_CREWS];
    this->crewMemberAmount = 0;
}

CFlight::CFlight(CFlightInfo &flightInfo, CPlane* plane) {
    this->flightInfo = new CFlightInfo(flightInfo);
    this->plane = new CPlane(*plane);
    this->crewMembers = new CCrewMember*[MAX_CREWS];
    this->crewMemberAmount = 0;
}

CFlight::CFlight(const CFlight& other) {
    this->flightInfo = new CFlightInfo(*other.flightInfo);
    if (other.plane != nullptr)
        this->plane = new CPlane(*other.plane);
    else
        this->plane = NULL;
    this->crewMemberAmount = other.crewMemberAmount;
    this->crewMembers = new CCrewMember* [MAX_CREWS];
    for (int i = 0; i < crewMemberAmount; i++)
        this->crewMembers[i] = new CCrewMember(*other.crewMembers[i]);
}

CFlightInfo& CFlight::GetFlightInfo() {
    return *new CFlightInfo(*flightInfo);
}

void CFlight::SetPlane(CPlane* newPlane) {
    this->plane = new CPlane(*newPlane);
}


bool CFlight::TakeOff() throw (CCompStringException) {
    if (plane == NULL)
        throw CCompStringException("CFlight: TakeOff: plane cannot be null.\n");
    int pilotAmount = 0;
    int superHostAmount = 0;
    for (int i = 0; i < crewMemberAmount; i++) { // count pilots and super-hosts
        if (strcmp(typeid(*crewMembers[i]).name(), "class CPilot") == 0)
            pilotAmount++;
        else if (((CHost*)crewMembers[i])->GetHostType() == CHost::eSuper)
            superHostAmount++;
    }
    if (strcmp(typeid(plane).name(), "class CCargo") == 0) { // cargo plane
        if (pilotAmount < 1)
            throw CCompStringException("CFlight: TakeOff: pilotAmount cannot be under 1 for a cargo plane!\n");
    }
    else { // passenger plane
        if (pilotAmount != 1 || superHostAmount > 1)
                throw CCompStringException("CFlight: TakeOff: pilotAmount cannot be 1 and superHostAmount cannot be over 1 for a passenger plane!\n");
    }
    plane->TakeOff(flightInfo->GetDuration());
    for (int i = 0; i < crewMemberAmount; i++)
        crewMembers[i]->TakeOff(flightInfo->GetDuration());
    return true;
}


void CFlight::operator+(CCrewMember* newCrewMember) {
    //If there's no place on flight.
    if (crewMemberAmount == MAX_CREWS)
        return;

    //Check for duplicate crew members.
    for (int i = 0; i < this->crewMemberAmount; i++)
        if (*crewMembers[i] == *newCrewMember)
            return;
    if (strcmp(typeid(*newCrewMember).name(), "class CHost") == 0)
        this->crewMembers[crewMemberAmount] =  new CHost(*(CHost*)newCrewMember);
    else if (strcmp(typeid(*newCrewMember).name(), "class CPilot") == 0)
        this->crewMembers[crewMemberAmount] = new CPilot(*(CPilot*)newCrewMember);
    crewMemberAmount++;
}

ostream &operator<<(ostream &outstream, const CFlight &flight) {
    outstream << "Flight " << *(flight.flightInfo);
    flight.plane == NULL ? outstream  << "No plane set yet.\n" : outstream << *flight.plane;
    outstream << "There are " << flight.crewMemberAmount << " crew members in flight:\n";
    for (int i = 0; i < flight.crewMemberAmount; i++)
        flight.crewMembers[i]->Print(outstream);
    return outstream;
}

bool CFlight::operator==(CFlight* otherFlight)  {
    if (!(*this->flightInfo == *otherFlight->flightInfo &&
          *this->plane == *otherFlight->plane &&
          this->crewMemberAmount == otherFlight->crewMemberAmount))
        return false;
    for (int i = 0; i < crewMemberAmount; i++) {
        if (!(this->crewMembers[i] == otherFlight->crewMembers[i]))
            return false;
    }
    return true;
}

CFlight::~CFlight() {
    for (int i = 0; i < this->crewMemberAmount; i++)
        crewMembers[i]->~CCrewMember();
    plane->~CPlane();
    delete flightInfo;
}

int CFlight::GetFNum() {
    return this->flightInfo->GetFNum();
}