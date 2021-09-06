#ifndef __CREW_MEMBER_H
#define __CREW_MEMBER_H

#include <iostream>
#include <string.h>
#include "helper.h"
using namespace std;

class CCrewMember {
protected:
	char* crewMemberName;
	int airMinutes;
public:
	CCrewMember(const char* crewMemberName, int airMinutes = 0);
	CCrewMember(const CCrewMember& other);
	~CCrewMember();
        int GetMinutes();
        char* GetCrewMemberName();
        void SetCrewMemberName(const char* newCrewMemberName);
        friend ostream& operator<<(ostream& outstream, const CCrewMember& crewMember);
        bool operator+=(int newAirMinutes);
        bool operator==(CCrewMember& otherCrewMember);
		bool UpdateMinutes(int newAirMinutes);
		void Print(ostream& outstream);
//		bool IsEqual(CCrewMember otherCrewMember);
        void GetPresent();
        void GetUniform();
        void TakeOff(int flightMinutes);
};
#endif