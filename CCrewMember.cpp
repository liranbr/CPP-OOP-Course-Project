#include "CrewMember.h"

CCrewMember::CCrewMember(const char* crewMemberName, int airMinutes) {
	this->crewMemberName = new char[strlen(crewMemberName) + 1];
	strcpy(this->crewMemberName, crewMemberName);
	this->airMinutes = airMinutes;
}

CCrewMember::CCrewMember(const CCrewMember& other) {
	strcpy(this->crewMemberName, other.crewMemberName);
	this->airMinutes = other.airMinutes;
}
CCrewMember::~CCrewMember() {
	delete[]crewMemberName;
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
	if (strcmp(this->crewMemberName, otherCrewMember.GetCrewMemberName()) == 0)
		return true; // strcmp returns 0 if they're equal
	return false;
}