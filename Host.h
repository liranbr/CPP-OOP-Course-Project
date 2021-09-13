#ifndef __HOST_H
#define __HOST_H

#include <iostream>
#include <fstream>
#include "helper.h"
#include "CrewMember.h"
using namespace std;

class CHost : public CCrewMember {
public:
	enum hostTypes { eRegular, eSuper, eCalcelan };
	const char* hostTypeNames[3] = { "Regular", "Super", "Calcelan" };
	CHost(const char* crewMemberName, hostTypes hostType, int airMinutes = 0);
	CHost(const CHost& other);
		hostTypes GetHostType();
		void GetPresent();
		void GetUniform();
		void Print(ostream& outstream);
		void PrintToFile(ofstream& outFile);
private:
	enum hostTypes hostType;
};
#endif