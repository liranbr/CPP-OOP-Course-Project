#ifndef __FLIGHT_COMPANY_H
#define __FLIGHT_COMPANY_H

#include <iostream>
#include "helper.h"
#include "CrewMember.h"
#include "Plane.h"
#include "Flight.h"
using namespace std;

class CFlightCompany {
private:
	char* nameOfCompany;
	CCrewMember** crewMembers;
	int crewMemberAmount;
	CPlane** planes;
	int planeAmount;
	CFlight** flights;
	int flightAmount;
public:
    CFlightCompany(const char* nameOfCompany);
    CFlightCompany(const char* filePath, int muda);
    ~CFlightCompany();
        char* GetNameOfCompany();
        void SetName(const char* nameOfCompany);
        void Print(ostream& outstream);
        void PrintFile(ofstream& outFile);
        bool AddCrewMember(CCrewMember& newMember);
        bool AddPlane(CPlane& newPlane);
        bool AddFlight(CFlight& newFlight);
        CFlight* GetFlightByNum(int flightID);
        CCrewMember* GetCrewMember(int index);
        CPlane& operator[](int planeIndex);
        void AddCrewToFlight(int flightID, int crewIndex);
        int GetCargoCount();
        int GetCrewCount();
        void PilotsToSimulator();
        void CrewGetPresent();
        void CrewGetUniform();
        bool TakeOffFlight(int flightID);
        CFlight* GetFlightFromFile(ifstream& inFile);
        void SaveToFile(const char* fileName);
};
#endif // !__FLIGHT_COMPANY_H
