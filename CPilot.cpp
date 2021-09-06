#include "Pilot.h"

CPilot::CPilot(const char* crewMemberName, bool isCaptain, CAddress* address, int airMinutes) : CCrewMember(crewMemberName, airMinutes) {
	this->isCaptain = isCaptain;
	if (address != nullptr)
		this->address = new CAddress(*address);
	else
		this->address = nullptr;
}

CPilot::CPilot(const CPilot& other) : CCrewMember(other.crewMemberName, other.airMinutes) {
	this->isCaptain = other.isCaptain;
	if (other.address != nullptr)
		this->address = new CAddress(*other.address);
	else
		this->address = nullptr;
}

CPilot::~CPilot() {
	delete address;
	delete[] crewMemberName;
}

void CPilot::GetPresent() {
	cout << this->crewMemberName << " thanking the company for receiving the holiday gift.\n";
}

void CPilot::GetUniform() {
	cout << this->crewMemberName << " this is the fifth time I get a new uniform – this is a waste of money!";
}

void CPilot::InviteToSimulator() {
	cout << "Pilot " << this->crewMemberName << "got the message will come soon.";
}

void CPilot::TakeOff(int flightMinutes) {
	this->operator+=(flightMinutes);
}

bool CPilot::operator+=(int additionalAirMinutes) {
	if (additionalAirMinutes <= 0)
		return false;
	this->airMinutes += (int) additionalAirMinutes * 1.1;
	return true;
}

bool CPilot::operator==(CPilot& otherPilot) {
	return CCrewMember::operator==(otherPilot) && this->address->operator==(*otherPilot.address);
}

