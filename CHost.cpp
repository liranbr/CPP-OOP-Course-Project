#include "Host.h"

CHost::CHost(const char* crewMemberName, hostTypes hostType, int airMinutes = 0) : CCrewMember(crewMemberName, airMinutes) {
	this->hostType = hostType;
}

CHost::CHost(const CHost& other) : CCrewMember(other.crewMemberName, other.airMinutes) {
	this->hostType = other.hostType;
}

void CHost::GetPresent() {
	cout << this->crewMemberName << "thanking the company for receiving the holiday gift.\nI wasn’t expecting it";
}

void CHost::GetUniform() {
	cout << "I think the new uniform is very nice!";
}

void CHost::TakeOff(int flightMinutes) {
	this->operator+=(flightMinutes); // add flight minutes to air time
}