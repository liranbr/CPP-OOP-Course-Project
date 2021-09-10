#include "PlaneCrewFactory.h"
#include <iostream>
#include <fstream>
#include "Plane.h"
#include "FlightInfo.h"
#include "CrewMember.h"
#include "Flight.h"
#include "FlightCompany.h"
#include "address.h"
#include "Pilot.h"
#include "Cargo.h"
#include "Host.h"
#include "FlightCompException.h"
using namespace std;

static PlaneType GetPlaneType(const CPlane* pPlane) {
	return strcmp(typeid(pPlane).name(), "class CPlane") == 0 ? PlaneType::eRegular : PlaneType::eCargo;
}

static CrewType GetCrewType(const CCrewMember* pCrew) {
	return strcmp(typeid(pCrew).name(), "class CHost") == 0 ? CrewType::eHost : CrewType::ePilot;
}

static void GetCompanyDataFromUser(CFlightCompany& comp) {

}

static CPlane* GetPlaneFromUser() {

}

static CCrewMember* GetCrewFromUser() {

}

static CCrewMember* GetCrewMemberFromFile(ifstream& inFile) {
	char buffer[BUFFER];
	CCrewMember* cm;
	try {
		inFile >> buffer;
		if (buffer[0] == 0)
			cm = new CHost(buffer);
		else
			cm = new CPilot(buffer);
	}
	catch (CCompFileException& e) {
		e.Show();
	}
	return cm;
}

static CPlane* GetPlaneFromFile(ifstream& inFile) {
    char buffer[BUFFER];
	char buffer2[BUFFER];
	CPlane* p;
	try {
		inFile >> buffer;
		if (buffer[0] == 0)
			p = new CPlane(buffer);
		else {
			inFile >> buffer2; // cargo also requires next line as input
			p = new CCargo(buffer, buffer2);
		}
	}
	catch (CCompFileException& e) {
		e.Show();
	}
	return p;
}
