#ifndef __PLANE_H
#define __PLANE_H

#include <iostream>
#include "helper.h"
using namespace std;

class CPlane {
private:
	int id;
	char modelName[MAX];
	int numOfChairs;
public:
	CPlane(int id, int numOfChairs, const char* modelName);
	int GetId();
	char* GetModelName();
	int GetNumOfChairs();
	void Print(ostream& outstream);
	bool IsEqual(CPlane otherPlane);
};
#endif