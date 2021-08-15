#include "Plane.h"

CPlane::CPlane(int numOfChairs, const char* modelName) {
	this->id = staticID;
	staticID++;
	this->numOfChairs = numOfChairs;
	this->modelName = new char[BUFFER];
	strcpy(this->modelName, modelName);
}

CPlane::CPlane(const CPlane& other) {
	this->id = other.id;
	this->numOfChairs = other.numOfChairs;
	this->modelName = new char[BUFFER];
	strcpy(this->modelName, other.modelName);
}

CPlane::~CPlane() {
	delete[]modelName;
}

int CPlane::GetId() {
	return id;
}

char* CPlane::GetModelName() {
	return _strdup(modelName);
}

int CPlane::GetNumOfChairs() {
	return numOfChairs;
}

void CPlane::Print(ostream& outstream) {
	outstream << "Plane " << id << " degem " << modelName << " seats " << numOfChairs << "\n";
}

void CPlane::operator++() {
	++numOfChairs;
}

void CPlane::operator++(int) {
	numOfChairs++;
}

ostream& operator>>(ostream& outstream, const CPlane& plane) {
	return outstream << "Plane " << plane.id << " degem " << plane.modelName << " seats " << plane.numOfChairs << "\n";
}

bool CPlane::IsEqual(CPlane otherPlane) {
	return this->id == otherPlane.GetId();
}