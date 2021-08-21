#include "CrewMember.h"

CCrewMember::CCrewMember(const char* crewMemberName, int airMinutes) {
	this->crewMemberName = new char[BUFFER];
	strcpy(this->crewMemberName, crewMemberName);
	this->airMinutes = airMinutes;
	this->id = START_ID;
	START_ID++;
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

int CCrewMember::GetId() {
    return id;
}

int CCrewMember::GetMinutes() {
	return airMinutes;
}

char* CCrewMember::GetCrewMemberName() {
    return _strdup(crewMemberName);
}

void CCrewMember::SetCrewMemberName(const char* newCrewMemberName) {
	strcpy(this->crewMemberName, newCrewMemberName);
}

friend ostream& operator<<(ostream& outstream, const CCrewMember& crewMember) {
    return outstream << "Crewmember " << crewMemberName << " minutes " << airMinutes << "\n";
}

bool CCrewMember::operator+=(int additionalAirMinutes) {
    if (additionalAirMinutes <= 0)
        return false;
    this->airMinutes += additionalAirMinutes;
    return true;
}

bool CCrewMember::operator==(CCrewMember& otherCrewMember) {
    return this->id == otherCrewMember.id;
}

bool CCrewMember::UpdateMinutes(int additionalAirMinutes) {
    if (additionalAirMinutes > 0) {
        airMinutes += additionalAirMinutes;
        return true;
    }
    return false;
}

//void CCrewMember::Print(ostream& outstream) {
//    outstream << "Crewmember " << crewMemberName << " minutes " << airMinutes << "\n";
//}

//bool CCrewMember::IsEqual(CCrewMember otherCrewMember) {
//	return this->id == otherCrewMember.id;
//}