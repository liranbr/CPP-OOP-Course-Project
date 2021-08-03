#include <iostream>
using namespace std;

class CFlightCompany {
private:
	char* nameOfCompany;
public:
	CFlightCompany(const char* nameOfCompany);
	char* GetNameOfCompany();
	void SetName(const char* nameOfCompany);
	void Print(ostream& outstream);
};