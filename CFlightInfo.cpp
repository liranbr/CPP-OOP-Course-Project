#include "FlightInfo.h"

CFlightInfo::CFlightInfo(const char *destination, int flightNum, int duration, int distance) {
    strcpy(this->destination, destination);
    this->flightNum = flightNum;
    this->duration = duration;
    this->distance = distance;
}

CFlightInfo::CFlightInfo(const CFlightInfo &other) {
    strcpy(this->destination, other.destination);
    this->flightNum = other.flightNum;
    this->duration = other.duration;
    this->distance = other.distance;
}

bool CFlightInfo::IsEqual(int otherFlightNum) {
    return this->flightNum == otherFlightNum;
}

//void CFlightInfo::Print(ostream& outstream) {
//	outstream << "Flight Info dest: " << destination << " Number " << flightNum << " minutes " << duration << " KM " << distance << "\n";
//}

ostream &operator<<(ostream &outstream, const CFlightInfo &otherFlightInfo) {
    return outstream << "Flight Info dest: " << otherFlightInfo.destination <<
    " Number " << otherFlightInfo.flightNum << " minutes " << otherFlightInfo.duration <<
    " KM " << otherFlightInfo.distance << "\n";
}

int CFlightInfo::GetFNum() {
    return flightNum;
}

char *CFlightInfo::GetDest() {
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

void CFlightInfo::SetDest(const char *destination) {
    strcpy(this->destination, destination);
}

void CFlightInfo::SetDuration(int duration) {
    this->duration = duration;
}

void CFlightInfo::SetDistance(int distance) {
    this->distance = distance;
}

bool CFlightInfo::operator==(const CFlightInfo &otherFlightInfo) const {
    return strcmp(this->destination, otherAddress.destination) == 0 &&
           this->flightNum == otherAddress.flightNum &&
           this->duration == otherAddress.duration &&
           this->distance == otherAddress.distance;
}

bool CFlightInfo::operator!=(const CFlightInfo &otherFlightInfo) const {
    return !(*this == otherFlightInfo);
}

CFlightInfo::operator int() const {
    return duration;
}