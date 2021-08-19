#include "Flight.h"

CFlight::CFlight(CFlightInfo &flightInfo) {
    this->flightInfo = new CFlightInfo(flightInfo);
    this->plane = NULL;
    *(this->crewMembers + 0) = nullptr;
    this->crewMemberAmount = 0;
}

CFlight::CFlight(CFlightInfo &flightInfo, CPlane &plane) {
    this->flightInfo = new CFlightInfo(flightInfo);
    this->plane = new CPlane(plane);
    *(this->crewMembers + 0) = nullptr;
    this->crewMemberAmount = 0;
}

void CFlight::SetPlane(CPlane &newPlane) {
    this->plane = new CPlane(*plane);
}

void CFlight::operator+(CCrewMember &newCrewMember) {
    //If there's no place on flight.
    if (crewMemberAmount == MAX_CREW)
        return;

    //Check for duplicate crew members.
    for (CCrewMember *crewMember : this->crewMembers)
        if (crewMember == newCrewMember)
            return;

    this->crewMembers[crewMemberAmount] = &newCrewMember;
    crewMemberAmount++;
}

ostream &operator<<(ostream &outstream, const CFlight &flight) {
    outstream << "Flight" << flight.flightInfo << flight.plane << crewString;
    outstream << "There are " << flight.crewMemberAmount << " crew members in flight:\n";
    for (CCrewMember cm : flight.crewMembers)
        outstream << cm;
    return outstream;
}

bool CFlight::operator==(const CFlight &otherFlight) const {
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
    for (CCrewMember *crewMember : this->crewMembers)
        crewMember->~CCrewMember();
    plane->~CPlane();
    delete flightInfo;
}