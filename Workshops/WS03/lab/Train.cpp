// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 2/2/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include"Train.h"
using namespace std;
namespace sdds {
	const int MAX_PEOPLE = 1000;
	const int MAX_SPEED = 320;


	void Train::set(const char* name, int people, double speed)
	{
		if (name != nullptr && strlen(name) !=0 && people > 0 && people < MAX_PEOPLE && speed > 0 && speed < MAX_SPEED)
		{
			strncpy(tname, name, MAX_NAME_LEN);
			tpeople = people;
			tspeed = speed;
		}
		else
		{
			tname[0] = 0;
			tpeople = -1;
			tspeed = -1;
		}
	}

	int Train::getNumberOfPeople() const
	{
		return tpeople;
	}

	const char* Train::getName() const
	{
		return tname;
	}

	double Train::getSpeed() const
	{
		return tspeed;
	}

	bool Train::isSafeEmpty() const
	{
		return tname == nullptr || tpeople == -1 || tspeed == -1;
	}

	void Train::display() const
	{
		if (isSafeEmpty())
		{
			cout << "Safe Empty State!" << endl;
		}
		else
		{
			
			cout << "NAME OF THE TRAIN : " << tname << endl;
			cout << "NUMBER OF PEOPLE  : " << tpeople << endl;
			cout << "SPEED             : " << tspeed  << " km/h" << endl;
		}
	}

}