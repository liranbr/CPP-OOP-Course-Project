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
	CAddress* GetAddress();
	void GetPresent();
	void GetUniform();
	bool CheckIfCaptain();
	void TakeOff(int flightMinutes);
	void InviteToSimulator();
	bool operator+=(int additionalAirMinutes);
	bool operator==(CPilot& otherPilot);
	void Print(ostream& outstream);
private:
	bool isCaptain;
	CAddress* address;
};
#endif