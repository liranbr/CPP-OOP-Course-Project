#ifndef __FLIGHT_COMPANY_H
#define __FLIGHT_COMPANY_H

#include <iostream>
#include "helper.h"
using namespace std;

class CFlightCompany {
private:
	char* nameOfCompany;
	CCrewMember* crewMembers[MAX_CREWS];
	int crewMemberAmount;
	CPlane* planes[MAX_PLANES];
	int planeAmount;
	CFlight* flights[MAX_FLIGHTS];
	int flightAmount;
public:
	CFlightCompany(const char* nameOfCompany);
	CFlightCompany(const CFlightCompany& other);
	~CFlightCompany();
		char* GetNameOfCompany();
		void SetName(const char* nameOfCompany);
		void Print(ostream& outstream);
		bool AddCrewMember(CCrewMember newMember);
		bool AddPlane(CPlane newPlane);
		bool AddFlight(CFlight newFlight);
};
#endif // !__FLIGHT_COMPANY_H
