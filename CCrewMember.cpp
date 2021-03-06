#include "CrewMember.h"
#include "FlightCompException.h"
#include <iostream>
#include <fstream>

CCrewMember::CCrewMember(const char* crewMemberName, int airMinutes) {
	this->crewMemberName = new char[BUFFER];
	strcpy(this->crewMemberName, crewMemberName);
	this->airMinutes = airMinutes;
}

CCrewMember::CCrewMember(const CCrewMember& other) {
	this->crewMemberName = new char[BUFFER];
	strcpy(this->crewMemberName, other.crewMemberName);
	this->airMinutes = other.airMinutes;
}
CCrewMember::~CCrewMember() {
	delete[] crewMemberName;
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

ostream& operator<<(ostream& outstream, const CCrewMember& crewMember) {
    return outstream << "Crewmember " << crewMember.crewMemberName <<
        " minutes " << crewMember.airMinutes << "\n";
}

bool CCrewMember::operator+=(int additionalAirMinutes) throw (CCompStringException) {
    if (additionalAirMinutes <= 0)
        throw CCompStringException("additionalAirMinutes cannot be under 0!\n");
    this->airMinutes += additionalAirMinutes;
    return true;
}

bool CCrewMember::operator==(CCrewMember& otherCrewMember) {
    return strcmp(this->crewMemberName, otherCrewMember.crewMemberName) == 0;
}

bool CCrewMember::UpdateMinutes(int additionalAirMinutes) {
    if (additionalAirMinutes > 0) {
        airMinutes += additionalAirMinutes;
        return true;
    }
    return false;
}

void CCrewMember::Print(ostream& outstream) {
    outstream << "Crewmember " << crewMemberName << " minutes " << airMinutes << "\n";
}

//bool CCrewMember::IsEqual(CCrewMember otherCrewMember) {
//	return this->id == otherCrewMember.id;
//}

void CCrewMember::GetPresent() {
    cout << "Thanks.\n";
}

void CCrewMember::GetUniform() {
    cout << "this isn't supposed to happen - I'm only a " << typeid(this).name() << "!\n";
}

void CCrewMember::TakeOff(int flightMinutes) {
    this->operator+=(flightMinutes); // add flight minutes to air time
}