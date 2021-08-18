#include "Flight.h"

CFlight::CFlight(CFlightInfo& flightInfo) {
	this->flightInfo = new CFlightInfo(flightInfo);
	this->plane = NULL;
	*(this->crewMembers + 0) = NULL;
	this->crewMemberAmount = 0;
}

CFlight::CFlight(CFlightInfo& flightInfo, CPlane& plane) {
	this->flightInfo = new CFlightInfo(flightInfo);
	this->plane = new CPlane(plane);
	*(this->crewMembers + 0) = NULL;
	this->crewMemberAmount = 0;
}

void CFlight::SetPlane(CPlane& newPlane) {
	this->plane = new CPlane(*plane);
}

//TODO continue work form here...
//We stopped at AddCrewMember.
//Verfiy delete with [] or without. 

void CFlight::operator+(CCrewMember& newCrewMember) {
	//If there's no place on flight.
	if (crewMemberAmount == MAX_CREW) 
		return;

	//Check for duplicate crew memebers.
	for (CCrewMember* crewMember : this->crewMembers)
		if (crewMember->IsEqual(newCrewMember)) 
			return;
	
	this->crewMembers[crewMemberAmount] = &newCrewMember;
	crewMemberAmount++;
}

ostream& operator<<(ostream& outstream, const CFlight& flight) {

}

bool CFlight::operator==(const CFlight& otherFlight) const {

}

CFlight::~CFlight() {
	for (CCrewMember* crewMember : this->crewMembers)
		crewMember->~CCrewMember();
	plane->~CPlane();
	delete flightInfo;

}