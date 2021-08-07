#include "Address.h"

CAddress::CAddress(int houseNum, const char* street, const char* city) {
	this->houseNum = houseNum;
	this->city = new char[strlen(street) + 1];
	this->city = new char[strlen(street) + 1];
	strcpy(this->city,  city);
	strcpy(this->street, street);
}

CAddress::CAddress(const CAddress& other) {
	houseNum = other.houseNum;
	this->city = new char[strlen(street) + 1];
	this->city = new char[strlen(street) + 1];
	strcpy(city, other.city);
	strcpy(street, other.street);
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

void CAddress::Print(ostream& outstream) {
	outstream << street << " " << houseNum << ", " << city << "\n";
}

void CAddress::UpdateAddress(const char* city, const char* street, int houseNum) {
	strcpy(this->city, city);
	strcpy(this->street, street);
	this->houseNum = houseNum;
}
