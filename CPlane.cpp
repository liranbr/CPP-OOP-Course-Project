#include "Plane.h"
 
class CPlane {
private:
	int id;
	char* modelName;
	int numOfChairs;
public:
	CPlane(int id, int numOfChairs, const char* modelName) {
		this->id = id;
		this->numOfChairs = numOfChairs;
		strcpy(this->modelName, modelName);
	}
	int GetId() {
		return id;
	}
	char* GetModelName() {
		return strdup(modelName);
	}
	int GetNumOfChairs() {
		return numOfChairs;
	}
	void Print(ostream& outstream) {
		outstream << "Plane " << id << "degem " << modelName << "seats " << numOfChairs;
	}
	bool IsEqual(CPlane otherPlane) {
		return this->id == otherPlane.GetId();
	}
};