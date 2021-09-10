#pragma once

#include <iostream>
using namespace std;

class CFlightCompException
{
public:
	virtual void Show() const {
		cout << "A general exception has occured!\n";
	};
};

class CCompStringException : public CFlightCompException {
private:
	char* message;
public:

	CCompStringException(const char* message) {
		strcpy(this->message, message);
	}

	virtual void Show() {
		cout << message;
	}
};

class CCompLimitException : public CFlightCompException {
private:
	int maxValue;
public:
	CCompLimitException(int maxValue) : maxValue(maxValue){}

	virtual void Show() {
		cout << "Comparison failed! the max value exceeded is: " << maxValue << "\n";
	}
};

class CCompFileException : public CFlightCompException {
private:
	char* fileName;
public:
	CCompFileException(char* fileName) : fileName(fileName) {}

	virtual void Show() {
		cout << "The file: " << fileName << " has caused the error!\n";
	}
};
