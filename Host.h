#ifndef __HOST_H
#define __HOST_H

#include <iostream>
#include "helper.h"
#include "CrewMember.h"
using namespace std;

class CHost : public CCrewMember {
public:
	enum hostTypes { eRegular, eSuper, eCalcelan };
	const char* hostTypeNames[3] = { "eRegular", "eSuper", "eCalcelan" };
	CHost(const char* crewMemberName, hostTypes hostType, int airMinutes = 0);
	CHost(const CHost& other);
		hostTypes GetHostType();
		void GetPresent();
		void GetUniform();
		void Print(ostream& outstream);
private:
	enum hostTypes hostType;
};
#endif