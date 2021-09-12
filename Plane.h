#ifndef __PLANE_H
#define __PLANE_H

#include <iostream>
#include <fstream>
#include "helper.h"
using namespace std;

class CPlane {
protected:
	int id;
	char* modelName;
	int numOfChairs;
public:
	static int lastID;
	CPlane(int numOfChairs, const char* modelName, int id = -1);
	//CPlane(int numOfChairs, const char* modelName, int id);
	CPlane(const CPlane& other);
	~CPlane();
		int GetId();
		char* GetModelName();
		int GetNumOfChairs();
		friend ostream& operator<<(ostream& outstream, CPlane& plane);
		bool operator==(const CPlane& otherPlane);
		void operator++();
		void operator++(int);
		void TakeOff(int flightDuration);
		virtual void Print(ostream& outstream);
		virtual void PrintToFile(ofstream& outFile, int index);
//		bool IsEqual(CPlane otherPlane);
};
#endif