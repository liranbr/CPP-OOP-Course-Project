#include "CrewMember.h"
 
class CCrewMember {
private:
	char* crewMemberName;
	int airMinutes;
public:
	CCrewMember(const char* crewMemberName, int airMinutes = 0) {
		strcpy(this->crewMemberName, crewMemberName);
		this->airMinutes = airMinutes;
	}
	bool UpdateMinutes(int additionalAirMinutes) {
		if (additionalAirMinutes > 0) {
			airMinutes += additionalAirMinutes;
			return true;
		}
		return false;
	}
	int GetMinutes() {
		return airMinutes;
	}
	void SetCrewMemberName(const char* newCrewMemberName) {
		strcpy(this->crewMemberName, newCrewMemberName);
	}
	char* GetCrewMemberName() {
		return strdup(crewMemberName);
	}
	void Print(ostream& outstream) {
		outstream << "Crewmember " << crewMemberName << "minutes" << airMinutes;
	}
	bool IsEqual(CCrewMember otherCrewMember) {
		return this->crewMemberName == otherCrewMember.GetCrewMemberName();
		/*
		if (strlen(crewMemberName) != strlen(otherCrewMemberName.GetCrewMemberName()))
			return false;
		for (int i = 0; i < strlen(crewMemberName); i++)
			if (*(crewMemberName + i) != *(otherCrewMemberName + i))
				return false;
		return true;
		*/
	}
};