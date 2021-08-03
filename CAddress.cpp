#include "Address.h"

CAddress::CAddress(int houseNum, const char* street, const char* city) {
	this->houseNum = houseNum;
	strcpy_s(this->city, strlen(city), city);
	strcpy_s(this->street, strlen(street), street);
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
	outstream << street << " " << houseNum << ", " << city;
}
void CAddress::UpdateAddress(const char* city, const char* street, int houseNum) {
	strcpy_s(this->city, strlen(city), city);
	strcpy_s(this->street, strlen(street), street);
	this->houseNum = houseNum;
}