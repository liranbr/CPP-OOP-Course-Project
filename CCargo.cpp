#include "Cargo.h"
#include "FlightCompException.h"
CCargo::CCargo(int numOfChairs, const char* modelName, float maxWeight,
	float maxVolume, float currentWeight, float currentVolume) throw (CCompStringException) :
	CPlane(numOfChairs, modelName) {
	if (currentWeight < 0 || currentVolume < 0)
		throw CCompStringException("currentWeight or currentVolume cannot be lower than 0.\n");
	if (maxWeight < 0 || maxVolume < 0)
		throw CCompStringException("maxWeight or maxVolume cannot be lower than 0.\n");
	this->maxWeight = maxWeight;
	this->maxVolume = maxVolume;
	this->currentWeight = currentWeight;
	this->currentVolume = currentVolume;
}

CCargo::CCargo(int numOfChairs, int id, const char* modelName, float maxWeight,
	float maxVolume, float currentWeight, float currentVolume) throw (CCompStringException) : 
	CPlane(numOfChairs, modelName, id) {
	if (currentWeight < 0 || currentVolume < 0)
		throw CCompStringException("currentWeight or currentVolume cannot be lower than 0.\n");
	if (maxWeight < 0 || maxVolume < 0)
		throw CCompStringException("maxWeight or maxVolume cannot be lower than 0.\n");
	this->maxWeight = maxWeight;
	this->maxVolume = maxVolume;
	this->currentWeight = currentWeight;
	this->currentVolume = currentVolume;
}

CCargo::CCargo(const CCargo& other) : CPlane(other.numOfChairs, other.modelName, other.id) {
	this->maxWeight = other.maxWeight;
	this->maxVolume = other.maxVolume;
	this->currentWeight = other.currentWeight;
	this->currentVolume = other.currentVolume;
}

CCargo::~CCargo() {
	delete[] modelName;
}

float CCargo::GetMaxVolume() {
	return maxVolume;
}

float CCargo::GetMaxWeight() {
	return maxWeight;

}

float CCargo::GetCurrentVolume() {
	return currentVolume;
}

float CCargo::GetCurrentWeight() {
	return currentWeight;
}

bool CCargo::Load(float incomingWeight, float incomingVolume) {
	float tempWeight = incomingWeight + currentWeight;
	float tempVolume = incomingVolume + currentVolume;
	if (tempWeight > maxWeight || tempVolume > maxVolume)
		return false;
	currentWeight = tempWeight;
	currentVolume = tempVolume;
	return true;
}

/*
ostream& operator<<(ostream& outstream, const CCargo& plane) {
	outstream << "Plane " << plane.id << " degem " << plane.modelName << " seats " << plane.numOfChairs << "\n";
	outstream << "Cargo M_vol " << plane.maxVolume << " M_Kg " << plane.maxWeight << " C_vol " << plane.currentVolume << " C_Kg " << plane.currentWeight << "\n";
	return outstream;
}*/

void CCargo::Print(ostream& outstream) {
	outstream << "Plane " << id << " degem " << modelName << " seats " << numOfChairs << "\n";
	outstream << "Cargo M_vol " << maxVolume << " M_Kg " << maxWeight << " C_vol " << currentVolume << " C_Kg " << currentWeight << "\n";
}

void CCargo::PrintToFile(ofstream& outFile, int index) {
	outFile << "1 ";
	(index == 0 ? outFile << CPlane::lastID << " " : outFile << "");
	outFile << id << " " << modelName << " " << numOfChairs << "\n";
	outFile << maxVolume << " " << maxWeight << " " << currentVolume << " " << currentWeight << "\n";
}