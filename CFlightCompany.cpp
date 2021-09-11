#include "FlightCompany.h"
#include "Pilot.h"
#include "CrewMember.h"
#include "Host.h"
#include "Pilot.h"
#include "Cargo.h"
#include "FlightCompException.h"
#include <iostream>
#include <fstream>
#include "PlaneCrewFactory.h"

int CPlane::lastID = 100;

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

CFlightCompany::CFlightCompany(const char* filePath, int muda) : CFlightCompany("") {
    ifstream inFile(filePath);
    inFile >> nameOfCompany; // set name of company
    int amount;

    inFile >> amount; // read crew member amount
    for (int i = 0; i < amount; i++) { // read crew members
        CCrewMember* cm = CPlaneCrewFactory::GetCrewMemberFromFile(inFile);
        AddCrewMember(*cm);
    }

    inFile >> amount; // read plane amount
    CPlaneCrewFactory::haveReadID = false; // about to read it from the first plane
    for (int i = 0; i < amount; i++) { // read planes
        CPlane* p = CPlaneCrewFactory::GetPlaneFromFile(inFile);
        AddPlane(*p);
    }

    inFile >> amount; // read flight amount
    for (int i = 0; i < amount; i++) { // read flights
        CFlight* f = GetFlightFromFile(inFile);
        AddFlight(*f);
    }

    inFile.close();
}

CFlight* CFlightCompany::GetFlightFromFile(ifstream& inFile) {
    CFlight* f = nullptr;
    try {
        char destination[BUFFER];
        int flightNum, duration, distance;
        bool hasPlane; // 1 => has plane, 0 => no plane
        inFile >> destination >> flightNum >> duration >> distance >> hasPlane;
        CFlightInfo* fi = new CFlightInfo(destination, flightNum, duration, distance);
        f = new CFlight(*fi);
        if (hasPlane) {
            int planeId;
            inFile >> planeId;
            for (int i = 0; i < planeAmount; i++)
                if (planes[i]->GetId() == planeId)
                    f->SetPlane(planes[i]);
        }
        int amount;
        inFile >> amount;
        for (int i = 0; i < amount; i++) {
            CCrewMember* cm = CPlaneCrewFactory::GetCrewMemberFromFile(inFile);
            cm->Print(cout);
            *f + cm;
        }
    }
    catch (CCompFileException& e) {
        e.Show();
    }
    return f;
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
    if (strlen(nameOfCompany) == 0)
        throw CCompStringException("nameOfCompany doesn't exist!");
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
        if (*(*(this->planes + i)) == newPlane)
            return false;
    if (strcmp(typeid(newPlane).name(), "class CPlane") == 0)
        this->planes[planeAmount] = new CPlane(newPlane);
    else if (strcmp(typeid(newPlane).name(), "class CCargo") == 0)
        this->planes[planeAmount] = new CCargo(*(CCargo*)&newPlane);
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

CPlane& CFlightCompany::operator[](int planeIndex) throw(CCompLimitException) {
    if (planeIndex >= 0 && planeIndex <= planeAmount - 1)
        return *planes[planeIndex];
    throw CCompLimitException(planeIndex);
}

void CFlightCompany::AddCrewToFlight(int flightID, int crewIndex) {
    *GetFlightByNum(flightID) + GetCrewMember(crewIndex);
}

int CFlightCompany::GetCargoCount() {
    int counter = 0;
    for (int i = 0; i < planeAmount; i++)
        if (strcmp(typeid(*planes[i]).name(), "class CCargo") == 0)
            counter++;
    return counter;
}

void CFlightCompany::PilotsToSimulator() {
    for (int i = 0; i < crewMemberAmount; i++)
        if (strcmp(typeid(*crewMembers[i]).name(), "class CPilot") == 0)
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
    try {
        return GetFlightByNum(flightID)->TakeOff();
    }
    catch (CCompStringException& e) {
        e.Show();
    }
}