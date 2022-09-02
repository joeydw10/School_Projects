// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 2/13/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include <iomanip>
#include "Robot.h"

using namespace std;
namespace sdds {
	void Robot::resetInfo()
	{
		m_name = nullptr;
		m_location = nullptr;
		m_weight = 0.0f;
		m_width = 0.0f;
		m_height = 0.0f;
		m_speed = 0.0f;
		m_deployed = false;
	}
	Robot::Robot()
	{
		resetInfo();
	}
	Robot::Robot(const char* rname, const char* rlocation, double rweight, double rwidth, double rheight, double rspeed, bool rdeployed)
	{
		if (rname != nullptr && rlocation != nullptr && rweight > 0 && rwidth > 0 && rheight > 0 && rspeed > 0 )
		{
			m_name = new char[strlen(rname) + 1];
			strcpy(m_name, rname);
			m_location = new char[strlen(rlocation) + 1];
			strcpy(m_location, rlocation);
			m_weight = rweight;
			m_width = rwidth;
			m_height = rheight;
			m_speed = rspeed;
			m_deployed = rdeployed;
		}
		else
		{
			resetInfo();
		}

	}
	Robot& Robot::set(const char* rname, const char* rlocation, double rweight, double rwidth, double rheight, double rspeed, bool rdeployed)
	{
		delete[] m_name;
		delete[] m_location;
		resetInfo();
		m_name = new char[strlen(rname) + 1];
		strcpy(m_name, rname);
		m_location = new char[strlen(rlocation) + 1];
		strcpy(m_location, rlocation);
		m_weight = rweight;
		m_width = rwidth;
		m_height = rheight;
		m_speed = rspeed;
		m_deployed = rdeployed;
		return *this;
	}
	void Robot::setLocation(const char* rlocation)
	{
		delete[] m_location;
		m_location = new char[strlen(rlocation) + 1];
		strcpy(m_location, rlocation);
	}
	void Robot::setDeployed(bool rdeployed)
	{
		m_deployed = rdeployed;
	}
	char* Robot::getName() const
	{
		return m_name;
	}
	char* Robot::getLocation() const
	{
		return m_location;
	}
	bool Robot::isDeployed() const
	{
		return m_deployed == true ? true: false;
	}
	bool Robot::isValid() const
	{
		bool res = false;
		if (m_name != nullptr && m_location != nullptr && m_weight > 0 && m_width > 0 && m_height > 0 && m_speed > 0 )
		{
			res = true;
		}
		return res;
	}
	double Robot::getSpeed() const
	{
		return m_speed;
	}
	void Robot::display() const
	{
		char tempYesNo[4] = "NO";
		cout.setf(ios::left);
		cout << "| " << setw(10) << m_name;
		cout << " | " << setw(15) << m_location;
		cout.setf(ios::right);
		cout << " | " << fixed << setprecision(1) << setw(6) << m_weight;
		cout << " | " << fixed << setprecision(1) << setw(6) << m_width;
		cout << " | " << fixed << setprecision(1) << setw(6) << m_height;
		cout << " | " << fixed << setprecision(1) << setw(6) << m_speed;
		cout.unsetf(ios::right);
		if (m_deployed)
			strcpy(tempYesNo, "YES");
		cout.setf(ios::left);
		cout << " | " << setw(8) << tempYesNo << " |" << endl;
	}

	Robot::~Robot()
	{
		delete[] m_name;
		m_name = nullptr;
		delete[] m_location;
		m_location = nullptr;
	}
	int conrtolRooomReport(const Robot robot[], int num_robots)
	{
		int res = -1;
		int deployed = 0;
		int faster = 0;
		cout << "                        ------ Robot Control Room -----" << endl;
		cout << "                    ---------------------------------------" << endl;
		cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
		cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
		for (int i = 0; i < num_robots && res == -1; i++)
		{
			if (robot[i].isValid() == true)
			{
				robot[i].display();
				if (robot[i].isDeployed())
				{
					deployed++;
					if (robot[i].getSpeed() > robot[faster].getSpeed())
					{
						faster = i;
					}
				}
			}
			else
			{
				res = i;
			}	
		}
		if (res == -1)
		{
			summary(robot,deployed, faster);
		}

		return res;
	}
	void summary(const Robot robot[], int deployed, int fastIndex)
	{
		cout << "|=============================================================================|" << endl;
		cout << "| SUMMARY:                                                                    |" << endl;
		cout << "| " << deployed << "  robots are deployed.                                                     |" << endl;
		cout << "| The fastest robot is:                                                       |" << endl;
		cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
		cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
		robot[fastIndex].display();
		cout << "|=============================================================================|" << endl;
	}
}