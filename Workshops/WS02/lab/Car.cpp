// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 1/26/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Car.h"
#include "cStrTools.h"
#include <iostream>
using namespace std;

namespace sdds {

	Car* TheCarPointer = nullptr;
	int allocationSize;
	int numOfCars;
	int carArraySize;

	void VBPLE_Title() {
		cout << "Vehicle Border Passing Log Entry" << endl;
		cout << "Enter the data in the following format :" << endl;
		cout << "Make and model, LicensePlate, MilitaryTime<ENTER>" << endl;
		cout << "Exit the program by entering the following :" << endl;
		cout <<	"X, < ENTER>" << endl;
	}

	void initialize(int allocSize) {
		numOfCars = 0;
		carArraySize = allocSize;
		allocationSize = allocSize;
		TheCarPointer = new Car[allocSize];
	}

	void deallocate(Car& C) {
		delete[] C.makeModel;
		C.makeModel = nullptr;
	}

	bool read(Car& C) {
		bool flag = false;
		char readMakeModel[61];
		read(readMakeModel, 60, ',');
		if (strCmp(readMakeModel, "X") != 0)
		{
			flag = true;
			C.makeModel = new char[strLen(readMakeModel) + 1];
			strCpy(C.makeModel, readMakeModel);
			read(C.licensePlate, 8, ',');
			cin >> C.time;
		}
		return flag;
	}
	void print(const Car& C) {
		cout << C.time << ": " << C.makeModel << "," << C.licensePlate << endl;
	}
	void record(const Car& C) {
		if (numOfCars >= carArraySize)
		{
			Car* temp = new Car[carArraySize + allocationSize];
			for (int i = 0; i < carArraySize; i++)
			{
				temp[i] = TheCarPointer[i];
			}
			delete[] TheCarPointer;
			TheCarPointer = temp;
			carArraySize += allocationSize;
		}
		TheCarPointer[numOfCars].makeModel = C.makeModel;
		strCpy(TheCarPointer[numOfCars].licensePlate, C.licensePlate);
		TheCarPointer[numOfCars].time = C.time;
		numOfCars++;
		
	}

	void endOfDay() {
		for (int i = 0; i < numOfCars; i++)
		{
			print(TheCarPointer[i]);
			deallocate(TheCarPointer[i]);
		}
		delete[] TheCarPointer;
		TheCarPointer = nullptr;
	}

}