#include <iostream>
#include <string.h>
using namespace std;

class CCrewMember {
private:
	char* crewMemberName;
	int airMinutes;
public:
	CCrewMember(const char* crewMemberName, int airMinutes = 0);
		bool UpdateMinutes(int newAirMinutes);
		int GetMinutes();
		void SetCrewMemberName(const char* newCrewMemberName);
		char* GetCrewMemberName();
		void Print(ostream& outstream);
		bool IsEqual(CCrewMember otherCrewMember);
};
