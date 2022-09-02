// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 2/6/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
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
			cout << "SPEED             : " << fixed << setprecision(2) << tspeed  << " km/h" << endl;
		}
	}

	bool Train::loadPeople(int people)
	{
		bool res = false;
		if (!isSafeEmpty()) {
			if ((tpeople + people) > MAX_PEOPLE)
			{
				tpeople = MAX_PEOPLE;
			}
			else if ((tpeople + people) < 0) {
				tpeople = 0;
			}
			else
			{
				tpeople += people;
				res = true;
			}
		}
		return res;
	}

	bool Train::changeSpeed(double speed)
	{
		bool res = false;
		if (!isSafeEmpty()){
		if ((tspeed + speed) > MAX_SPEED)
		{
			tspeed = MAX_SPEED;
		}
		else if ((tspeed + speed) < 0) {
			tspeed = 0;
		}
		else
		{
			tspeed += speed;
		}
		res = true;
		}
		return res;
	}

	int transfer(Train& train1, Train& train2)
	{
		int people1 = train1.getNumberOfPeople();// gets the people from the first train
		int people2 = train2.getNumberOfPeople();// get the people from the second train
		int moved = -1;// keeping track of how much was moved or not
		if (!train1.isSafeEmpty() && !train2.isSafeEmpty()) {// fixed old way I made temp class for this before idk what i was thinking 
			
			if ((people1 + people2) > MAX_PEOPLE) // checks for the max people if it is greater than Max People(1000) than it will move from the second train to the first train
			{
				moved = MAX_PEOPLE - people1;//gets the moved people from both the trains
				train1.loadPeople(moved);// adds the moved people to the 1st train
				train2.loadPeople(-moved);// removes people who want to train 1 
			}
		}
		return moved;
	}

}