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
	CFlightInfo flightInfo;
	CPlane plane;
	CCrewMember crewMembers[MAX_CREW];
	int crewMemberAmount;

public:
	CFlight(CFlightInfo& flightInfo);
	CFlight(CFlightInfo& flightInfo, CPlane& plane);
	void SetPlane(CPlane& newPlane);
	void operator+(CCrewMember& newCrewMember);
	friend ostream& operator<<(ostream& outstream, const CFlight& flight);
	bool operator==(const CFlight& otherFlight) const;
};

#endif