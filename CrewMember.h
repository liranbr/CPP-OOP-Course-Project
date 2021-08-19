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
	int id;
public:
    static int START_ID;
	CCrewMember(const char* crewMemberName, int airMinutes = 0);
	CCrewMember(const CCrewMember& other);
	~CCrewMember();
		bool UpdateMinutes(int newAirMinutes);
		bool operator+=(int newAirMinutes);
        bool operator==(CCrewMember& otherCrewMember);
        int GetId();
		int GetMinutes();
		void SetCrewMemberName(const char* newCrewMemberName);
		char* GetCrewMemberName();
		void Print(ostream& outstream);
//		bool IsEqual(CCrewMember otherCrewMember);
};
int CCrewMember::START_ID = 1000;
#endif