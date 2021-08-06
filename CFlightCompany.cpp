#include "FlightCompany.h"

CFlightCompany::CFlightCompany(const char* nameOfCompany) {
	strcpy(this->nameOfCompany, nameOfCompany);
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