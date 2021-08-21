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
	~CAddress();
    char* GetCity();
    char* GetStreet();
    int GetHouseNum();
    friend ostream& operator<<(ostream& outstream, const CAddress& otherAddress);
    friend istream& operator>>(istream& instream, const CAddress& address);
    bool operator==(const CAddress& otherAddress) const;
    bool operator!=(const CAddress& otherAddress) const;
    void UpdateAddress(const char* city, const char* street, int houseNum);
    char* GetCurrentAddress();

};
#endif