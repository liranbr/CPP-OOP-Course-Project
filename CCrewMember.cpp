#include "CrewMember.h"

CCrewMember::CCrewMember(const char* crewMemberName, int airMinutes) {
	this->crewMemberName = new char[BUFFER];
	strcpy(this->crewMemberName, crewMemberName);
	this->airMinutes = airMinutes;
	this->id = staticID;
	staticID++;
}

CCrewMember::CCrewMember(const CCrewMember& other) {
	this->id = other.id;
	this->crewMemberName = new char[BUFFER];
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

void CCrewMember::operator+=(int newAirMinutes) {
	this->airMinutes += newAirMinutes;
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
	return this->id == otherCrewMember.id;
}