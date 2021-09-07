#pragma once
#include "Plane.h"
class CCargo : public CPlane {
private:
	float maxWeight;
	float maxVolume;
	float currentWeight;
	float currentVolume;
public:
	CCargo(int numOfChairs, const char* modelName, float maxWeight,
		float maxVolume, float currentWeight = 0, float currentVolume = 0);
	CCargo(const CCargo& other);
	~CCargo();
	bool Load(float incomingWeight, float incomingVolume);
	void TakeOff(int flightDuration);
	void Print(ostream& outstream);

};

