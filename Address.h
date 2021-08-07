#ifndef __ADDRESS_H
#define __ADDRESS_H

#include <iostream>
#include <string.h>
#include "helper.h"
using namespace std;

class CAddress {
private:
	char* city;
	char* street;
	int houseNum;
public:
	CAddress(int houseNum, const char* street, const char* city = "Tel Aviv");
	CAddress(const CAddress& other);
		char* GetCity();
		char* GetStreet();
		int GetHouseNum();
		void Print(ostream& outstream);
		void UpdateAddress(const char* city, const char* street, int houseNum);
};
#endif