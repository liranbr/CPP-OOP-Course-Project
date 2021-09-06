#ifndef __FLIGHT_COMPANY_H
#define __FLIGHT_COMPANY_H

#include <iostream>
#include "helper.h"
#include "CrewMember.h"
#include "Plane.h"
#include "Flight.h"
using namespace std;

class CFlightCompany {
private:
	char* nameOfCompany;
	CCrewMember** crewMembers;
	int crewMemberAmount;
	CPlane** planes;
	int planeAmount;
	CFlight** flights;
	int flightAmount;
public:
	CFlightCompany(const char* nameOfCompany);
	/*CFlightCompany(const CFlightCompany& other);*/
	~CFlightCompany();
		char* GetNameOfCompany();
		void SetName(const char* nameOfCompany);
		void Print(ostream& outstream);
		bool AddCrewMember(CCrewMember& newMember);
		bool AddPlane(CPlane& newPlane);
		bool AddFlight(CFlight& newFlight);
		CPlane* GetPlane(int planeIndex);
		CFlight* GetFlight(int flightID);
		CCrewMember* GetCrewMember(int index);
		void AddCrewToFlight(int flightID, int crewIndex);
		int GetCargoCount();
		void PilotsToSimulator();
		void CrewGetPresent();
		void CrewGetUniform();
		bool TakeOffFlight(int flightID);
};
#endif // !__FLIGHT_COMPANY_H
