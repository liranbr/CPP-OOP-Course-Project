#include "FlightInfo.h"

CFlightInfo::CFlightInfo(const char* destination, int flightNum, int duration, int distance) {
	strcpy(this->destination, destination);
	this->flightNum = flightNum;
	this->duration = duration;
	this->distance = distance;
}
bool CFlightInfo::IsEqual(int otherFlightNum) {
	return this->flightNum == otherFlightNum;
}
void CFlightInfo::Print(ostream& outstream) {
	outstream << "Flight Info dest: " << destination << " Number " << flightNum << " minutes " << duration << " KM " << distance << "\n";
}
int CFlightInfo::GetFlightNum() {
	return flightNum;
}
char* CFlightInfo::GetDest() {
	return _strdup(destination);
}
int CFlightInfo::GetDuration() {
	return duration;
}
int CFlightInfo::GetDistance() {
	return distance;
}
void CFlightInfo::SetFlightNum(int flightNum) {
	this->flightNum = flightNum;
}
void CFlightInfo::SetDest(const char* destination) {
	strcpy(this->destination, destination);
}
void CFlightInfo::SetDuration(int duration) {
	this->duration = duration;
}
void CFlightInfo::SetDistance(int distance) {
	this->distance = distance;
}