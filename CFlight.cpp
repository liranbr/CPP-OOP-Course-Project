#include "Flight.h"

CFlight::CFlight(CFlightInfo& flightInfo) {
	this->flightInfo = CFlightInfo(flightInfo);
}

CFlight::CFlight(CFlightInfo& flightInfo, CPlane& plane) {
	this->flightInfo = CFlightInfo(flightInfo);
	this->plane = CPlane(plane);
}

void CFlight::SetPlane(CPlane& newPlane) {
	this->plane = CPlane(plane);
}

void CFlight::operator+(CCrewMember& newCrewMember) {
	//If there's no place on flight.
	if (crewMemberAmount == MAX_CREW) 
		return;

	//Check for duplicate crew memebers.
	for (CCrewMember crewMember : this->crewMembers)
		if (crewMember.IsEqual(newCrewMember)) 
			return;
	
	this->crewMembers[crewMemberAmount] = newCrewMember;
	crewMemberAmount++;
}

ostream& operator<<(ostream& outstream, const CFlight& flight) {

}

bool CFlight::operator==(const CFlight& otherFlight) const {

}