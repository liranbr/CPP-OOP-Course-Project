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
	CPlane(int id, int numOfChairs, const char* modelName);
	CPlane(const CPlane& other);
	~CPlane();
		int GetId();
		char* GetModelName();
		int GetNumOfChairs();
		void Print(ostream& outstream);
		friend ostream& operator>>(ostream& outstream, const CPlane& plane);
		bool IsEqual(CPlane otherPlane);
};
#endif