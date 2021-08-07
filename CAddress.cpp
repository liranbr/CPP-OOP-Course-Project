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

void CAddress::Print(ostream& outstream) {
	outstream << street << " " << houseNum << ", " << city << "\n";
}

void CAddress::UpdateAddress(const char* newCity, const char* newStreet, int newHouseNum) {
	//delete[]city;
	//delete[]street;
	//this->city = new char[BUFFER];
	//this->street = new char[BUFFER];
	strcpy(this->city, newCity);
	strcpy(this->street, newStreet);
	this->houseNum = newHouseNum;
}
