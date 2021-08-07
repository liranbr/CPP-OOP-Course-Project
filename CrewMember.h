#ifndef __CREW_MEMBER_H
#define __CREW_MEMBER_H

#include <iostream>
#include <string.h>
#include "helper.h"
using namespace std;

class CCrewMember {
private:
	char* crewMemberName;
	int airMinutes;
public:
	CCrewMember(const char* crewMemberName, int airMinutes = 0);
	CCrewMember(const CCrewMember& other);
	~CCrewMember();
		bool UpdateMinutes(int newAirMinutes);
		int GetMinutes();
		void SetCrewMemberName(const char* newCrewMemberName);
		char* GetCrewMemberName();
		void Print(ostream& outstream);
		bool IsEqual(CCrewMember otherCrewMember);
};
#endif