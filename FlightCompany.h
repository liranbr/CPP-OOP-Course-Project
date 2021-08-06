#ifndef __FLIGHT_COMPANY_H
#define __FLIGHT_COMPANY_H

#include <iostream>
#include "helper.h"
using namespace std;

class CFlightCompany {
private:
	char nameOfCompany[MAX];
public:
	CFlightCompany(const char* nameOfCompany);
	char* GetNameOfCompany();
	void SetName(const char* nameOfCompany);
	void Print(ostream& outstream);
};
#endif // !__FLIGHT_COMPANY_H
