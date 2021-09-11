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

		strcpy(buffer2, buffer);
		char* tokens[MAX];
		int i = 0;
		tokens[i] = strtok(buffer2, " ");
		while (tokens[i] != NULL) {
			i++;
			tokens[i] = strtok(NULL, " ");
		}
		int isFirst = 0; // if first plane, there's an additional lastID field........
		if (i == 5) {
			CPlane::lastID = atoi(tokens[1]);
			isFirst = 1;
		}
		if (atoi(tokens[0]) == 0) // if regular plane
			p = new CPlane(atoi(tokens[3 + isFirst]), tokens[2 + isFirst], atoi(tokens[1 + isFirst]));
			// CPlane(seats, degem, id)

		else { // if cargo plane
			inFile >> buffer2; // cargo also requires next line as input
			i = 0;
			char* tokens2[MAX];
			tokens2[i] = strtok(buffer2, " ");
			while (tokens2[i] != NULL) {
				i++;
				tokens2[i] = strtok(NULL, " ");
			}
			// CCargo(seats, id, degem,
			//	maxWeight, maxVolume, weight, volume)
			p = new CCargo(atoi(tokens[3 + isFirst]), atoi(tokens[1 + isFirst]), tokens[2 + isFirst],
				atof(tokens2[1]), atof(tokens2[0]), atof(tokens2[3]), atof(tokens2[2]));
		}
	}
	catch (CCompFileException& e) {
		e.Show();
	}
	return p;
}
