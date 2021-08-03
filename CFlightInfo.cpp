#include "FlightInfo.h"

class CFlightInfo {
private:
	int flightNum;
	char destination[MAX];
	int duration;
	int distance;
public:
	CFlightInfo(const char destination[MAX], int flightNum, int duration, int distance) {
		strcpy(this->destination, destination);
		this->flightNum = flightNum;
		this->duration = duration;
		this->distance = distance;
	}

	bool IsEqual(int otherFlightNum) {
		return this->flightNum == otherFlightNum;
	}
	void Print(ostream& outstream) {
		outstream << "Flight Info dest: " << destination << " Number " << flightNum << " minutes " << duration << " KM " << distance;
	}

	int GetFlightNum() { 
		return flightNum;}
	char* GetDest() {
		return strdup(destination);}
	int GetDuration() {
		return duration;}
	int GetDistance() {
		return distance;}

	void SetFlightNum(int flightNum) { 
		this->flightNum = flightNum;}
	void SetDest(const char destination[MAX]) {
		strcpy(this->destination, destination);}
	void SetDuration(int duration) { 
		this->duration = duration;}
	void SetDistance(int distance) {
		this->distance = distance;}
};