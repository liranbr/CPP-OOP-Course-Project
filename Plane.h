#ifndef __PLANE_H
#define __PLANE_H

#include <iostream>
#include "helper.h"
using namespace std;

class CPlane {
private:
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
		friend ostream& operator<<(ostream& outstream, const CPlane& plane);
		bool operator==(CPlane& otherPlane);
		void operator++();
		void operator++(int);
//		void Print(ostream& outstream);
//		bool IsEqual(CPlane otherPlane);
};
#endif