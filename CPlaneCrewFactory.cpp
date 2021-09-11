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

 void CPlaneCrewFactory::GetCompanyDataFromUser(CFlightCompany& comp) {

}

 CPlane* CPlaneCrewFactory::GetPlaneFromUser() {
	 return nullptr;
}

 CCrewMember* CPlaneCrewFactory::GetCrewFromUser() {
	 return nullptr;
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
			p = new CCargo(seats, degem, maxKG, maxVolume, kg, volume);
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
