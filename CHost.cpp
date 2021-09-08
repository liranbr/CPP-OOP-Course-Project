#include "Host.h"

CHost::CHost(const char* crewMemberName, hostTypes hostType, int airMinutes) : CCrewMember(crewMemberName, airMinutes) {
	this->hostType = hostType;
}

CHost::CHost(const CHost& other) : CCrewMember(other.crewMemberName, other.airMinutes) {
	this->hostType = other.hostType;
}

CHost::hostTypes CHost::GetHostType() {
	return hostType;
}

void CHost::GetPresent() {
	cout << this->crewMemberName << " thanking the company for receiving the holiday gift.\nI wasn't expecting it\n";
}

void CHost::GetUniform() {
	cout << crewMemberName <<": I think the new uniform is very nice!\n";
}


void CHost::Print(ostream& outstream) {
	outstream << "Host " << hostTypeNames[hostType] << " " << crewMemberName << " minutes " << airMinutes << "\n";
}