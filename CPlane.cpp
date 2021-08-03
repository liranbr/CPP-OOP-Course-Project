#include "Plane.h"
 
CPlane::CPlane(int id, int numOfChairs, const char* modelName) {
	this->id = id;
	this->numOfChairs = numOfChairs;
	strcpy_s(this->modelName, strlen(modelName), modelName);
}
int CPlane::GetId() {
	return id;
}
char* CPlane::GetModelName() {
	return strdup(modelName);
}
int CPlane::GetNumOfChairs() {
	return numOfChairs;
}
void CPlane::Print(ostream& outstream) {
	outstream << "Plane " << id << "degem " << modelName << "seats " << numOfChairs;
}
bool CPlane::IsEqual(CPlane otherPlane) {
	return this->id == otherPlane.GetId();
}