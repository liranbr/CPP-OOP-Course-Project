#include "FlightInfo.h"
#include "FlightCompException.h"
CFlightInfo::CFlightInfo(const char *destination, int flightNum, int duration, int distance) 
throw (CCompStringException) {
    SetDest(destination);
    SetFNum(flightNum);
    SetDuration(duration);
    SetDistance(distance);
}

CFlightInfo::CFlightInfo(const CFlightInfo &other) {
    strcpy(this->destination, other.destination);
    this->flightNum = other.flightNum;
    this->duration = other.duration;
    this->distance = other.distance;
}

int CFlightInfo::GetFNum() {
    return flightNum;
}

void CFlightInfo::SetFNum(int flightNum) throw (CCompStringException) {
    if (flightNum < 0)
        throw CCompStringException("flightNum cannot be lower than 0\n");
    this->flightNum = flightNum;
}

char *CFlightInfo::GetDest() {
    return _strdup(destination);
}

void CFlightInfo::SetDest(const char *destination) throw (CCompStringException) {
    if (strlen(destination) > MAX)
        throw CCompStringException("destination name is too long!\n");
    strcpy(this->destination, destination);
}

int CFlightInfo::GetDuration() {
    return duration;
}

void CFlightInfo::SetDuration(int duration) throw (CCompStringException) {
    if (duration < 0)
        throw CCompStringException("duration cannot be lower than 0!\n");
    this->duration = duration;
}

int CFlightInfo::GetDistance() {
    return distance;
}

void CFlightInfo::SetDistance(int distance) throw (CCompStringException) {
    if (distance < 0)
        throw CCompStringException("distance cannot be lower than 0!\n");
    this->distance = distance;
}

ostream& operator<<(ostream& outstream, const CFlightInfo& otherFlightInfo) {
    return outstream << "Flight Info dest: " << otherFlightInfo.destination <<
                     " Number " << otherFlightInfo.flightNum << " minutes " << otherFlightInfo.duration <<
                     " KM " << otherFlightInfo.distance << "\n";
}

bool CFlightInfo::operator==(const CFlightInfo &otherFlightInfo) const {
    return strcmp(this->destination, otherFlightInfo.destination) == 0 &&
           this->flightNum == otherFlightInfo.flightNum &&
           this->duration == otherFlightInfo.duration &&
           this->distance == otherFlightInfo.distance;
}

bool CFlightInfo::operator!=(const CFlightInfo &otherFlightInfo) const {
    return !(*this == otherFlightInfo);
}

CFlightInfo::operator int() const {
    return duration;
}