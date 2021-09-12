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
	CCargo(int numOfChairs, int id, const char* modelName, float maxWeight,
		float maxVolume, float currentWeight = 0, float currentVolume = 0); 
	// we put ID before the char*, to make the two constructors discernable
	CCargo(const CCargo& other);
	~CCargo();
	float GetMaxVolume();
	float GetMaxWeight();
	float GetCurrentVolume();
	float GetCurrentWeight();
	bool Load(float incomingWeight, float incomingVolume);
	void Print(ostream& outstream);

};

