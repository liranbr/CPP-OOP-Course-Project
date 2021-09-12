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
}

CAddress* CPilot::GetAddress() {
	return address;
}

void CPilot::GetPresent() {
	cout << this->crewMemberName << " thanking the company for receiving the holiday gift.\n";
}

void CPilot::GetUniform() {
	cout << this->crewMemberName << ": this is the fifth time I get a new uniform, this is a waste of money!\n";
}

void CPilot::InviteToSimulator() {
	cout << "Pilot " << this->crewMemberName << " got the message will come soon.\n";
}

void CPilot::TakeOff(int flightMinutes) {
	this->operator+=(flightMinutes);
}

bool CPilot::operator+=(int additionalAirMinutes) {
	if (additionalAirMinutes <= 0)
		return false;
	this->airMinutes += ((int) additionalAirMinutes * 1.1);
	return true;
}

bool CPilot::operator==(CPilot& otherPilot) {
	return CCrewMember::operator==(otherPilot) && this->address->operator==(*otherPilot.address);
}

void CPilot::Print(ostream& outstream) {
	outstream << "Pilot " << crewMemberName << " minutes " << airMinutes << (isCaptain ? ", a Captain. " : ", not a Captain. ");
	if (address != nullptr)
		outstream << "Home: " << *address;
	else
		outstream << "\n";
}

void CPilot::PrintToFile(ofstream& outFile) {
	outFile << "1 " << crewMemberName << " " << airMinutes << " ";
	(address != nullptr ? outFile << "1 " <<*address : outFile << "0\n");
	outFile << (isCaptain ? "1\n" : "0\n");
}

bool CPilot::CheckIfCaptain() {
	return isCaptain;
}
