#include "FlightCompany.h"
#include "Pilot.h"
#include "CrewMember.h"
#include "Host.h"
#include "Pilot.h"

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
    outstream << "There are " << crewMemberAmount << " Crew members:\n";
    for (int i = 0; i < crewMemberAmount; i++)
        crewMembers[i]->Print(outstream);
    outstream << "There are " << planeAmount << " Planes:\n";
    for (int i = 0; i < planeAmount; i++)
        outstream << *planes[i];
    outstream << "There are " << flightAmount << " Flights:\n";
    for (int i = 0; i < flightAmount; i++)
        outstream << *flights[i];
}

bool CFlightCompany::AddCrewMember(CCrewMember& newMember) {
    if (crewMemberAmount >= MAX_CREWS)
        return false;
    for (int i = 0; i < crewMemberAmount; i++) 
        if (*this->crewMembers[i] == newMember)
            return false;
    if (strcmp(typeid(newMember).name(), "class CHost") == 0)
        this->crewMembers[crewMemberAmount] = new CHost(*(CHost*)&newMember);
    else if (strcmp(typeid(newMember).name(), "class CPilot") == 0)
        this->crewMembers[crewMemberAmount] = new CPilot(*(CPilot*)&newMember);
    crewMemberAmount++;
    return true;
}

bool CFlightCompany::AddPlane(CPlane& newPlane) {
    if (planeAmount >= MAX_PLANES)
        return false;
    for (int i = 0; i < planeAmount; i++) 
        if (*(*(this->planes + i)) == &newPlane)
            return false;
    
    this->planes[planeAmount] = new CPlane(newPlane);
    planeAmount++;
    return true;
}

bool CFlightCompany::AddFlight(CFlight& newFlight) {
    if (flightAmount >= MAX_FLIGHTS)
        return false;
    for (int i = 0; i < flightAmount; i++) 
        if (*(*(this->flights + i)) == &newFlight)
            return false;
    
    this->flights[flightAmount] = new CFlight(newFlight);
    flightAmount++;
    return true;
}

CFlight* CFlightCompany::GetFlightByNum(int flightID) {
    for (int i = 0; i < flightAmount; i++)
        if (flights[i]->GetFNum() == flightID)
            return flights[i];
    return nullptr;
}

CCrewMember* CFlightCompany::GetCrewMember(int index) {
    if (index < 0 || index >= crewMemberAmount)
        return nullptr;
    return crewMembers[index];
}

CPlane* CFlightCompany::GetPlane(int planeIndex) {
    if (planeIndex >= 0 && planeIndex <= planeAmount - 1)
        return planes[planeIndex];
    return nullptr;
}

void CFlightCompany::AddCrewToFlight(int flightID, int crewIndex) {
    *GetFlightByNum(flightID) + GetCrewMember(crewIndex);
}

int CFlightCompany::GetCargoCount() {
    int counter = 0;
    for (int i = 0; i < planeAmount; i++)
        if (strcmp(typeid(planes[i]).name(), "CCargo") == 0)
            counter++;
    return counter;
}

void CFlightCompany::PilotsToSimulator() {
    for (int i = 0; i < crewMemberAmount; i++)
        if (strcmp(typeid(crewMembers[i]).name(), "CPilot") == 0)
            ((CPilot*)crewMembers[i])->InviteToSimulator();
}

void CFlightCompany::CrewGetPresent() {
    for (int i = 0; i < crewMemberAmount; i++)
        crewMembers[i]->GetPresent();
}

void CFlightCompany::CrewGetUniform() {
    for (int i = 0; i < crewMemberAmount; i++)
        crewMembers[i]->GetUniform();
}

bool CFlightCompany::TakeOffFlight(int flightID) {
    return GetFlightByNum(flightID)->TakeOff();
}