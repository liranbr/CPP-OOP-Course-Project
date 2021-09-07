#ifndef __FLIGHT_H
#define __FLIGHT_H

#include <iostream>
#include "helper.h"
#include "FlightInfo.h"
#include "Plane.h"
#include "CrewMember.h"

using namespace std;

class CFlight
{
private:
	CFlightInfo* flightInfo;
	CPlane* plane;
	CCrewMember** crewMembers;
	int crewMemberAmount;

public:
	CFlight(CFlightInfo& flightInfo);
	CFlight(CFlightInfo& flightInfo, CPlane* plane);
	CFlight(const CFlight& other);
	CFlightInfo* GetFlightInfo();
	void SetPlane(CPlane* newPlane);
	bool TakeOff();
	void operator+(CCrewMember* newCrewMember);
	friend ostream& operator<<(ostream& outstream, const CFlight& flight);
	bool operator==(CFlight* otherFlight) ;
	int GetFNum();
	~CFlight();
};

#endif