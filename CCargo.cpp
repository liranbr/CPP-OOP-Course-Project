#include "Cargo.h"

CCargo::CCargo(int numOfChairs, const char* modelName, float maxWeight,
	float maxVolume, float currentWeight, float currentVolume) :
	CPlane(numOfChairs, modelName) {
	this->maxWeight = maxWeight;
	this->maxVolume = maxVolume;
	this->currentWeight = currentWeight;
	this->currentVolume = currentVolume;
}

CCargo::CCargo(const CCargo& other) : CPlane(other.numOfChairs, other.modelName) {
	this->maxWeight = other.maxWeight;
	this->maxVolume = other.maxVolume;
	this->currentWeight = other.currentWeight;
	this->currentVolume = other.currentVolume;
}

CCargo::~CCargo() {
	delete[] modelName;
}

bool CCargo::load(float incomingWeight, float incomingVolume) {
	float tempWeight = incomingWeight + currentWeight;
	float tempVolume = incomingVolume + currentVolume;
	if (tempWeight > maxWeight || tempVolume > maxVolume)
		return false;
	currentWeight = tempWeight;
	currentVolume = tempVolume;
	return true;
}

void CCargo::TakeOff(int flightDuration) {
	cout << "Need to add " << flightDuration << " to my log book.\n";
}