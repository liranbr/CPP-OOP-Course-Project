#include "FlightCompany.h"

CFlightCompany::CFlightCompany(const char* nameOfCompany) {
	this->nameOfCompany = new char[strlen(nameOfCompany) + 1];
	strcpy(this->nameOfCompany, nameOfCompany);
}

CFlightCompany::CFlightCompany(const CFlightCompany& other) {
	strcpy(this->nameOfCompany, other.nameOfCompany);
}

CFlightCompany::~CFlightCompany() {
	delete[]nameOfCompany;
}

char* CFlightCompany::GetNameOfCompany() {
	return _strdup(nameOfCompany);
}

void CFlightCompany::SetName(const char* nameOfCompany) {
	strcpy(this->nameOfCompany, nameOfCompany);
}

void CFlightCompany::Print(ostream& outstream) {
	outstream << "Flight company: " << nameOfCompany << "\n";
}