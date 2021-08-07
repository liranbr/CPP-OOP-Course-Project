#include "Plane.h"
 
CPlane::CPlane(int id, int numOfChairs, const char* modelName) {
	this->id = id;
	this->numOfChairs = numOfChairs;
	this->modelName = new char[strlen(modelName) + 1];
	strcpy(this->modelName, modelName);
}

CPlane::CPlane(const CPlane& other) {
	this->id = other.id;
	this->numOfChairs = other.numOfChairs;
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

bool CPlane::IsEqual(CPlane otherPlane) {
	return this->id == otherPlane.GetId();
}