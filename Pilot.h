#ifndef __PILOT_H
#define __PILOT_H

#include <iostream>
#include "helper.h"
#include "CrewMember.h"
#include "Address.h"
using namespace std;

class CPilot : public CCrewMember {
public:
	CPilot(const char* crewMemberName, bool isCaptain, CAddress* address = nullptr, int airMinutes = 0);
	CPilot(const CPilot& other);
	~CPilot();
	void GetPresent();
	void GetUniform();
	void TakeOff(int flightMinutes);
	void InviteToSimulator();
	bool operator+=(int additionalAirMinutes);
	bool operator==(CPilot& otherPilot);
private:
	bool isCaptain;
	CAddress* address;
};
#endif