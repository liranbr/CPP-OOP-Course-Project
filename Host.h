#ifndef __HOST_H
#define __HOST_H

#include <iostream>
#include "helper.h"
#include "CrewMember.h"
using namespace std;

class CHost : virtual public CCrewMember {
public:
	enum hostTypes { eRegular, eSuper, eCalcelan };
	CHost(const char* crewMemberName, hostTypes hostType, int airMinutes = 0);
	CHost(const CHost& other);
		void GetPresent();
		void GetUniform();
		void TakeOff(int flightMinutes);
private:
	enum hostTypes hostType;
};
#endif