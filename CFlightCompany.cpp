#include "FlightCompany.h"
#include "CrewMember.h"
#include "Plane.h"
#include "Flight.h"
#include "FlightInfo.h"

CFlightCompany::CFlightCompany(const char* nameOfCompany) {
	this->nameOfCompany = new char[BUFFER];
	strcpy(this->nameOfCompany, nameOfCompany);
}

CFlightCompany::CFlightCompany(const CFlightCompany& other) {
	this->nameOfCompany = new char[BUFFER];
	strcpy(this->nameOfCompany, other.nameOfCompany);
}

CFlightCompany::~CFlightCompany() {
	delete[]nameOfCompany;
}

char* CFlightCompany::GetNameOfCompany() {
	return _strdup(nameOfCompany);
}

void CFlightCompany::SetName(const char* nameOfCompany) {
	strcpy(this->nameOfCompany, nameOfCompany);
}

void CFlightCompany::Print(ostream& outstream) {
	outstream << "Flight company: " << nameOfCompany << "\n";
}

bool CFlightCompany::AddCrewMember(CCrewMember newMember) {
    if (crewMemberAmount >= MAX_CREWS)
        return false;
    for (CCrewMember cm : this->crewMembers) // check for duplicate
        if (cm == newMember)
            return false;
    this->crewMembers[crewMemberAmount] = new CCrewMember(newMember);
    crewMemberAmount++;
    return true;
}

bool CFlightCompany::AddPlane(CPlane newPlane) {
    if (planeAmount >= MAX_PLANES)
        return false;
    for (CPlane cp : this->planes) // check for duplicate
        if (cp == newPlane)
            return false;
    this->planes[PlaneAmount] = new CPlane(newPlane);
    planeAmount++;
    return true;
}

bool CFlightCompany::AddFlight(CFlight newFlight) {
    if (flightAmount >= MAX_FLIGHTS)
        return false;
    for (CFlight cf : this->flights) // check for duplicate
        if (cf == newFlight)
            return false;
    this->flights[flightAmount] = new CFlight(newFlight);
    flightAmount++;
    return true;
}

CFlight& CFlightCompany::GetFlight(int flightID) {
    for (CFlight& cf : this->flights) {
        if (cf.GetFNum() == flightID)
            return cf;
    }
    return nullptr;
}

CCrewMember& CFlightCompany::GetCrewMember(int memberID) {
    for (CCrewMember& cm : this->crewMembers) {
        if (cm.GetId() == memberID)
            return cm;
    }
    return nullptr;
}

void CFlightCompany::AddCrewToFlight(int flightID, int memberID) {
    CFlight* flight = GetFlight(flightID);
    flight = flight + GetCrewMember(memberID);
}

CPlane& CFlightCompany::GetPlane(int planeIndex) {
    if (planeIndex > 0 && planeIndex <= planeAmount - 1)
        return planes[planeIndex];
}