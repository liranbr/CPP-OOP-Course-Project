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
#include "String.h"
#include "helper.h"

using namespace std;

bool CPlaneCrewFactory::haveReadID = false;

PlaneType CPlaneCrewFactory::GetPlaneType(const CPlane* pPlane) {
	return strcmp(typeid(pPlane).name(), "class CPlane") == 0 ? PlaneType::eRegular : PlaneType::eCargo;
}

CrewType CPlaneCrewFactory::GetCrewType(const CCrewMember* pCrew) {
	return strcmp(typeid(pCrew).name(), "class CHost") == 0 ? CrewType::eHost : CrewType::ePilot;
}

CCrewMember* CPlaneCrewFactory::GetCrewMemberFromFile(ifstream& inFile) {
	CCrewMember* cm = nullptr;
	try {
		int minutes, pilotOrHost; // 1 => pilot, 0 => host
		char name[BUFFER];
		inFile >> pilotOrHost >> name >> minutes;
		if (pilotOrHost) { // is a pilot
			bool hasAddress;
			inFile >> hasAddress;
			CAddress* address = nullptr;
			if (hasAddress) {
				int houseNum;
				char street[BUFFER], city[BUFFER];
				inFile >> houseNum >> street >> city;
				address = new CAddress(houseNum, street, city);
			}
			bool isCaptain;
			inFile >> isCaptain;
			cm = new CPilot(name, isCaptain, address, minutes);
		}
		else { // is a host
			int typeNum;
			inFile >> typeNum;
			cm = new CHost(name, (CHost::hostTypes)typeNum, minutes);
		}
	}
	catch (CCompFileException& e) {
		e.Show();
	}
	return cm;
}

CPlane* CPlaneCrewFactory::GetPlaneFromFile(ifstream& inFile) {
	CPlane* p = nullptr;
	try {
		int cargoOrPlane, id, seats; // 1 => cargo, 0 => plane
		char degem[BUFFER];
		inFile >> cargoOrPlane;
		if (!haveReadID) { // if first plane, essentially
			inFile >> CPlane::lastID;
			haveReadID = true;
		}
		inFile >> id >> degem >> seats;
		if (cargoOrPlane) { // if cargo
			float maxVolume, maxKG, volume, kg;
			inFile >> maxVolume >> maxKG >> volume >> kg;
			p = new CCargo(seats, id, degem, maxKG, maxVolume, kg, volume);
		}
		else { // if plane
			p = new CPlane(seats, degem, id);
		}
	}
	catch (CCompFileException& e) {
		e.Show();
	}
	return p;
}

void CPlaneCrewFactory::GetCompanyDataFromUser(CFlightCompany& comp) {
	int crewOrPlane = ReadInt("To add a plane, enter 0. To add a crew member, enter 1: ");
	if (crewOrPlane) // add crew member
		comp.AddCrewMember(*GetCrewFromUser());
	else // add plane
		comp.AddPlane(*GetPlaneFromUser());
	cout << "Added to " << comp.GetNameOfCompany() << endl;
}


CPlane* CPlaneCrewFactory::GetPlaneFromUser() {
	CPlane* p = nullptr;
	int cargoOrPlane = ReadInt("To add a regular plane, enter 0. To add a cargo plane, enter 1: ");
	cout << "Enter the plane's details.\n";
	int id = ReadInt("ID: ");
	cout << "Model name: ";
	char degem[BUFFER];
	cin >> degem;
	int seats = ReadInt("Amount of seats: ");
	if (cargoOrPlane) {
		cout << "Enter the cargo details.\n";
		float maxKG = ReadFloat("Maximum cargo weight: ");
		float maxVolume = ReadFloat("Maximum cargo volume: ");
		float kg = ReadFloat("Current cargo weight: ");
		float volume = ReadFloat("Current cargo volume: ");
		p = new CCargo(seats, id, degem, maxKG, maxVolume, kg, volume);
	}
	else
		p = new CPlane(seats, degem, id);
	return p;
}

CCrewMember* CPlaneCrewFactory::GetCrewFromUser() {
	CCrewMember* cm = nullptr;
	int pilotOrHost = ReadInt("To add a host, enter 0. To add a pilot, enter 1: ");
	cout << "Enter their details.\nName: ";
	char name[BUFFER];
	cin >> name;
	int minutes = ReadInt("Air minutes: ");
	if (pilotOrHost) { // is a pilot
		int hasAddress = ReadInt("Do they have a home address? enter 1(yes) or 0(no): ");
		CAddress* address = nullptr;
		if (hasAddress) {
			int houseNum = ReadInt("House number: ");
			char street[BUFFER], city[BUFFER];
			cout << "Street: ";
			cin >> street;
			cout << "City: ";
			cin >> city;
			address = new CAddress(houseNum, street, city);
		}
		int isCaptain = ReadInt("Is the pilot a Captain? enter 1(yes) or 0(no): ");
		cm = new CPilot(name, isCaptain, address, minutes);
	}
	else { // is a host
		int typeNum = ReadInt("Host type (0 for Regular, 1 for Super, 2 for Calcelan): ");
		cm = new CHost(name, (CHost::hostTypes)typeNum, minutes);
	}
	return cm;
}


int CPlaneCrewFactory::ReadInt(const char* instruction) {
	cout << instruction;
	int i;
	cin >> i;
	return i;
}

float CPlaneCrewFactory::ReadFloat(const char* instruction) {
	cout << instruction;
	float f;
	cin >> f;
	return f;
}
