#include <iostream>
using namespace std;

class CFlightCompany {
private:
	char* nameOfCompany;
public:
	CFlightCompany(const char* nameOfCompany);
	int GetNameOfCompany();
	void SetName(const char* nameOfCompany);
	void Print(ostream& outstream);
};