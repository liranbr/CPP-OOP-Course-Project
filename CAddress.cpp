#include "Address.h"

CAddress::CAddress(int houseNum, const char* street, const char* city) {
	this->houseNum = houseNum;
	strcpy(this->city,  city); // MAYBE +1 TO STRLEN?
	strcpy(this->street, street);
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