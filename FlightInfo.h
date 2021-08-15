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
		bool IsEqual(int otherFlightNum);
		void Print(ostream& outstream);
		int GetFlightNum();
		char* GetDest();
		int GetDuration();
		int GetDistance();
		void SetFlightNum(int flightNum);
		void SetDest(const char* destination);
		void SetDuration(int duration);
		void SetDistance(int distance);
		friend ostream& operator<<(ostream& outstream, const CFlightInfo& otherFlightInfo);
};
#endif