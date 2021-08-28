#ifndef __FLIGHT_INFO_H
#define __FLIGHT_INFO_H


#include <iostream>
#include "helper.h"
using namespace std;

class CFlightInfo {
private:
	int flightNum;
	char destination[MAX];
	int duration;
	int distance;
public:
	CFlightInfo(const char* destination, int flightNum, int duration, int distance);
	CFlightInfo(const CFlightInfo& other);
    int GetFNum();
    void SetFNum(int flightNum);
    char* GetDest();
    void SetDest(const char* destination);
    int GetDuration();
    void SetDuration(int duration);
    int GetDistance();
    void SetDistance(int distance);
    friend ostream& operator<<(ostream& outstream, const CFlightInfo& otherFlightInfo);
    bool operator==(const CFlightInfo& otherFlightInfo) const;
    bool operator!=(const CFlightInfo& otherFlightInfo) const;
    operator int() const;
};
#endif