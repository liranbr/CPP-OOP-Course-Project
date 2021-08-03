#include "CrewMember.h"

CCrewMember::CCrewMember(const char* crewMemberName, int airMinutes = 0) {
	strcpy_s(this->crewMemberName, strlen(crewMemberName), crewMemberName);
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
	strcpy_s(this->crewMemberName, strlen(newCrewMemberName), newCrewMemberName);
}
char* CCrewMember::GetCrewMemberName() {
	return _strdup(crewMemberName);
}
void CCrewMember::Print(ostream& outstream) {
	outstream << "Crewmember " << crewMemberName << "minutes" << airMinutes;
}
bool CCrewMember::IsEqual(CCrewMember otherCrewMember) {
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