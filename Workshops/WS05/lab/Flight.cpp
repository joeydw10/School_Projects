// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 2/17/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

   void Flight::emptyPlane() {
      m_passengers = 0;
      m_fuel = 0;
      strcpy(m_title, "EmptyPlane");
   }


   // New Flight
   Flight::Flight() {
      emptyPlane();
   }
   Flight::Flight(int passengers, double fuel, const char* title) {
      emptyPlane();
      if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
         fuel <= FuelTankCapacity) {
         m_passengers = passengers;
         m_fuel = fuel;
         strcpy(m_title, title);
      }
   }
   Flight::operator bool() const
   {
      bool res = false;
      if (m_passengers > 0 && m_fuel >= m_passengers * 600)
      {
         res = true;
      }
      return res;
   }
   Flight::operator int() const
   {
      return (int)m_passengers;
   }
   Flight::operator double() const
   {
      return(double)m_fuel;
   }
   Flight::operator const char*() const
   {
      return (const char*)m_title;
   }
   bool Flight::operator~() const
   {
      return m_passengers == 0 ? true : false;
   }
   Flight& Flight::operator=(Flight& f)
   {
      m_passengers = f.m_passengers;
      m_fuel = f.m_fuel;
      strcpy(m_title, f.m_title);
      f.emptyPlane();
      return *this;
   }
   Flight& Flight::operator=(int passengers)
   {
      if (passengers > 0 && passengers < Boen747Capacity)
      {
         m_passengers = passengers;
      }
      return *this;
   }
   Flight& Flight::operator=(double fuel)
   {
      if (fuel > 0 && fuel < FuelTankCapacity)
      {
         m_fuel = fuel;
      }
      return *this;
   }
   Flight& Flight::operator+=(double fuel)
   {
      if (fuel > 0 && m_fuel < FuelTankCapacity)
      {
         m_fuel += fuel;
         fuelCheck(m_fuel);
      }
      return *this;
   }
   Flight& Flight::operator+=(int passengers)
   {

      if (passengers > 0 && m_passengers < Boen747Capacity)
      {
         m_passengers += passengers;
         passengerCheck(m_passengers);
      }
      return *this;
   }
   Flight& Flight::operator-=(double fuel)
   {
      if (fuel > 0 && m_fuel > 0) {
         m_fuel -= fuel;
         if (m_fuel < 0)
         {
            m_fuel = 0;
         }
      }
      return *this;
   }
   Flight& Flight::operator-=(int passengers)
   {
      if (passengers > 0 && passengers <= m_passengers )
      {
         m_passengers -= passengers;
      }
      return *this;
   }
   Flight& Flight::operator<<(Flight& right)
   {
      int rem = 0;
      if (*this && right)
      {
         m_passengers += right.m_passengers;
         if (m_passengers > Boen747Capacity) {
            rem = m_passengers - Boen747Capacity;
            right.m_passengers = rem;
         }
         else
         {
            m_passengers += right.m_passengers;
            right.m_passengers = 0;
         }
      }
      return *this;
   }
   Flight& Flight::operator>>(Flight& right)
   {
      int rem = 0;
      if (*this && right)
      {
         right.m_passengers += m_passengers;
         if (right.m_passengers > Boen747Capacity) {
            rem = right.m_passengers - Boen747Capacity;
            m_passengers = rem;
            right.m_passengers -= rem;
         }
         else
         {
            right.m_passengers += m_passengers;
            m_passengers = 0;
         }
      }
      return *this;
   }
   int Flight::passengerCheck(int value, int min, int max)
   {
      if (value > min && value < max) {
         value = max;
      }
      else if (value < min) {
         value = min;
      }
      return value;
   }
   double Flight::fuelCheck(double value, double min, double max)
   {
      if (value > min && value < max) {
         value = max;
      }
      else if (value < min) {
         value = min;
      }
      return value;
   }
   std::ostream& Flight::display() const {

      if (*this) {
         cout << " Flight  |  Ready to Depart";
         cout << " ";
         cout.width(10);
         cout << std::string(*this);
         cout << " | ";
         cout << "Pass: ";
         cout.width(10);
         cout << int(*this);
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << double(*this);
         cout.unsetf(ios::right);
         cout << " Liters";
      }
      else if (~*this) {
         cout << " Flight  |  Empty Plane    ";
      }
      else {
         cout << " Flight  |  Low Fuel       ";
         cout << " ";
         cout.width(10);
         cout << (const char*)(*this);
         cout << " | ";
         cout << "Pass: ";
         cout.width(10);
         cout << int(*this);
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << double(*this);
         cout.unsetf(ios::right);
         cout << " Liters";
      }
      return cout;
   }



   int operator+(const Flight& right, const Flight& left)
   {
      int total = 0;
      if (right && left)
      {
         total = (int)right + (int)left;
      }
      return total;
   }

   int operator+=(int& value, const Flight& left)
   {
      value += (int)left;
      return value;
   }

}