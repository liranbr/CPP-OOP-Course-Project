#ifndef __PLANE_H
#define __PLANE_H

#include <iostream>
#include "helper.h"
using namespace std;

class CPlane {
protected:
	int id;
	char* modelName;
	int numOfChairs;
	static int staticID;
public:
	CPlane(int numOfChairs, const char* modelName);
	CPlane(const CPlane& other);
	~CPlane();
		int GetId();
		char* GetModelName();
		int GetNumOfChairs();
		friend ostream& operator<<(ostream& outstream, CPlane& plane);
		bool operator==(CPlane* otherPlane);
		void operator++();
		void operator++(int);
		void TakeOff(int flightDuration);
		virtual void Print(ostream& outstream);
//		bool IsEqual(CPlane otherPlane);
};
#endif