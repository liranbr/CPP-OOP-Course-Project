#include "Address.h"

CAddress::CAddress(int houseNum, const char* street, const char* city) {
	this->houseNum = houseNum;
	this->city = new char[BUFFER];
	this->street = new char[BUFFER];
	strcpy(this->city,  city);
	strcpy(this->street, street);
}

CAddress::CAddress(const CAddress& other) {
	houseNum = other.houseNum;
	this->city = new char[BUFFER];
	this->street = new char[BUFFER];
	strcpy(this->city, other.city);
	strcpy(this->street, other.street);
}


CAddress::~CAddress() {
	delete[]street;
	delete[]city;
}

char* CAddress::GetCity() {
	return _strdup(city);
}

char* CAddress::GetStreet() {
	return _strdup(street);
}

int CAddress::GetHouseNum() {
	return houseNum;
}

char* CAddress::GetCurrentAddress() {
	char tempString[MAX];
	sprintf(tempString, "%s %s %d", this->street, this -> houseNum, this->city);
	return tempString;
}


//void CAddress::Print(ostream& outstream) {
//	outstream << street << " " << houseNum << ", " << city << "\n";
//}

ostream& operator<<(ostream& outstream, const CAddress& otherAddress) {
	return outstream << otherAddress.street << " " << otherAddress.houseNum << ", " << otherAddress.city << "\n";
}

istream& operator>>(istream& instream,  CAddress& address) {
	char tempCity[MAX];
	char tempStreet[MAX];
	int tempHouseNum = 0;
	instream >> tempHouseNum >> tempStreet >> tempCity;
	address.UpdateAddress(tempCity, tempStreet, tempHouseNum);
	return instream;
}

//void CAddress::UpdateAddress(const char* newCity, const char* newStreet, int newHouseNum) {
//	//delete[]city;
//	//delete[]street;
//	//this->city = new char[BUFFER];
//	//this->street = new char[BUFFER];
//	strcpy(this->city, newCity);
//	strcpy(this->street, newStreet);
//	this->houseNum = newHouseNum;
//}

bool CAddress::operator==(const CAddress& otherAddress) const {
	return strcmp(this->city, otherAddress.city) == 0 && strcmp(this->street, otherAddress.street) == 0 && this->houseNum == otherAddress.houseNum;
}

bool CAddress::operator!=(const CAddress& otherAddress) const {
	return !(*this == otherAddress);
}
