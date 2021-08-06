#include "CrewMember.h"

CCrewMember::CCrewMember(const char* crewMemberName, int airMinutes) {
	strcpy(this->crewMemberName, crewMemberName);
	this->airMinutes = airMinutes;
}
bool CCrewMember::UpdateMinutes(int additionalAirMinutes) {
	if (additionalAirMinutes > 0) {
		airMinutes += additionalAirMinutes;
		return true;
	}
	return false;
}
int CCrewMember::GetMinutes() {
	return airMinutes;
}
void CCrewMember::SetCrewMemberName(const char* newCrewMemberName) {
	strcpy(this->crewMemberName, newCrewMemberName);
}
char* CCrewMember::GetCrewMemberName() {
	return _strdup(crewMemberName);
}
void CCrewMember::Print(ostream& outstream) {
	outstream << "Crewmember " << crewMemberName << " minutes " << airMinutes << "\n";
}
bool CCrewMember::IsEqual(CCrewMember otherCrewMember) {
	char* tempCrewMemberName= otherCrewMember.GetCrewMemberName();
	/*this->crewMemberName == otherCrewMember.GetCrewMemberName();*/
	
	if (strlen(crewMemberName) != strlen(tempCrewMemberName))
		return false;
	for (int i = 0; i < strlen(crewMemberName); i++)
		if (*(crewMemberName + i) != *(tempCrewMemberName + i))
			return false;
	return true;
	
}