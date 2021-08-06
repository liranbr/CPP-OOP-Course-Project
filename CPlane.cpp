#include "Plane.h"
 
CPlane::CPlane(int id, int numOfChairs, const char* modelName) {
	this->id = id;
	this->numOfChairs = numOfChairs;
	strcpy(this->modelName, modelName);
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