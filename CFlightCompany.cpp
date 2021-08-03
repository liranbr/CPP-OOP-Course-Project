#include "FlightCompany.h"

class CFlightCompany {
private:
	char* nameOfCompany;
public:
	CFlightCompany(const char* nameOfCompany) {
		strcpy(this->nameOfCompany, nameOfCompany);
	}
	char* GetNameOfCompany() {
		return strdup(nameOfCompany);
	}
	void SetName(const char* nameOfCompany) {
		strcpy(this->nameOfCompany, nameOfCompany);
	}
	void Print(ostream& outstream) {
		outstream << "Flight company: " << nameOfCompany;
	}
};