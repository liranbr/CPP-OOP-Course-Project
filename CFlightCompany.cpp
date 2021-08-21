#include "FlightCompany.h"

int CPlane::staticID = 100;

CFlightCompany::CFlightCompany(const char* nameOfCompany) {
	this->nameOfCompany = new char[BUFFER];
	strcpy(this->nameOfCompany, nameOfCompany);
    this->crewMembers = new CCrewMember*[MAX_CREWS];
    this->crewMemberAmount = 0;
    this->planes = new CPlane*[MAX_PLANES];
    this->planeAmount = 0;
    this->flights = new CFlight*[MAX_FLIGHTS];
    this->flightAmount = 0;
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
    for (int i = 0; i < crewMemberAmount; i++) 
        if (*(*(this->crewMembers + i)) == newMember)
            return false;
    
    this->crewMembers[crewMemberAmount] = new CCrewMember(newMember);
    crewMemberAmount++;
    return true;
}

bool CFlightCompany::AddPlane(CPlane newPlane) {
    if (planeAmount >= MAX_PLANES)
        return false;
    for (int i = 0; i < planeAmount; i++) 
        if (*(*(this->planes + i)) == &newPlane)
            return false;
    
    this->planes[planeAmount] = new CPlane(newPlane);
    planeAmount++;
    return true;
}

bool CFlightCompany::AddFlight(CFlight newFlight) {
    if (flightAmount >= MAX_FLIGHTS)
        return false;
    for (int i = 0; i < flightAmount; i++) 
        if (*(*(this->flights + i)) == newFlight)
            return false;
    
    this->flights[flightAmount] = new CFlight(newFlight);
    flightAmount++;
    return true;
}

CFlight* CFlightCompany::GetFlight(int flightID) {
    for (int i = 0; i < flightAmount; i++)
        if (flights[i]->GetFNum() == flightID)
            return flights[i];
    return nullptr;
}

CCrewMember CFlightCompany::GetCrewMember(int memberID) {
    for (int i = 0; i < flightAmount; i++)
        if (crewMembers[i]->GetId() == memberID)
            return *crewMembers[i];
    return nullptr;
}

CPlane* CFlightCompany::GetPlane(int planeIndex) {
    if (planeIndex > 0 && planeIndex <= planeAmount - 1)
        return planes[planeIndex];
    return nullptr;
}

void CFlightCompany::AddCrewToFlight(int flightID, int memberID) {
    CFlight flight = *GetFlight(flightID);
    flight + GetCrewMember(memberID);
}