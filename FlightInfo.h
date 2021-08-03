#include <iostream>
using namespace std;
constexpr auto MAX = 63;

class CFlightInfo {
private:
	int flightNum;
	char destination[MAX];
	int duration;
	int distance;
public:
	CFlightInfo(const char destination[MAX], int flightNum, int duration, int distance);
	bool IsEqual(int otherFlightNum);
	void Print(ostream& outstream);
	int GetFlightNum();
	char* GetDest();
	int GetDuration();
	int GetDistance();
	void SetFlightNum(int flightNum);
	void SetDest(const char destination[MAX]);
	void SetDuration(int duration);
	void SetDistance(int distance);
};