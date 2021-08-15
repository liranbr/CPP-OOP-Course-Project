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
public:
	static int staticID;
	CPlane(int numOfChairs, const char* modelName);
	CPlane(const CPlane& other);
	~CPlane();
		int GetId();
		char* GetModelName();
		int GetNumOfChairs();
		void Print(ostream& outstream);
		friend ostream& operator>>(ostream& outstream, const CPlane& plane);
		void operator++();
		void operator++(int);
		bool IsEqual(CPlane otherPlane);
};
int CPlane::staticID = 100;
#endif