#include <iostream>
using namespace std;

class CPlane {
private:
	int id;
	char* modelName;
	int numOfChairs;
public:
	CPlane(int id, int numOfChairs, const char* modelName);
	int GetId();
	char* GetModelName();
	int GetNumOfChairs();
	void Print(ostream& outstream);
	bool IsEqual(CPlane otherPlane);
};