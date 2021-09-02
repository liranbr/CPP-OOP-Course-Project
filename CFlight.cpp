#include "Flight.h"

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

void CFlight::SetPlane(CPlane* newPlane) {
    this->plane = new CPlane(*newPlane);
}

void CFlight::operator+(CCrewMember newCrewMember) {
    //If there's no place on flight.
    if (crewMemberAmount == MAX_CREWS)
        return;

    //Check for duplicate crew members.
    for (int i = 0; i < this->crewMemberAmount; i++)
        if (*crewMembers[i] == newCrewMember)
            return;

    this->crewMembers[crewMemberAmount] = &newCrewMember;
    crewMemberAmount++;
}

ostream &operator<<(ostream &outstream, const CFlight &flight) {
    outstream << "Flight" << *(flight.flightInfo);
    flight.plane == NULL ? outstream  << "No plane set yet.\n" : outstream << *flight.plane;
    outstream << "There are " << flight.crewMemberAmount << " crew members in flight:\n";
    for (int i = 0; i < flight.crewMemberAmount; i++)
        outstream << flight.crewMembers[i];
    return outstream;
}

bool CFlight::operator==(const CFlight& otherFlight) const {
    if (!(this->flightInfo == otherFlight.flightInfo &&
          this->plane == otherFlight.plane &&
          this->crewMemberAmount == otherFlight.crewMemberAmount))
        return false;
    for (int i = 0; i < crewMemberAmount; i++) {
        if (!(this->crewMembers[i] == otherFlight.crewMembers[i]))
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