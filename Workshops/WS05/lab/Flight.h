// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 2/17/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

   const int Boen747Capacity = 388;
   const int FuelTankCapacity = 238840;

   class Flight {

      int m_passengers = 0;
      double m_fuel = 0;
      char m_title[16];
      void emptyPlane();

   public:
      Flight();
      Flight(int passengers, double fuel, const char* title);
      // type conversions
      operator bool()const;
      operator int()const;
      operator double()const;
      operator const char*()const;
      // Unary 
      bool operator ~() const;
      // Binary
      Flight& operator=( Flight& f);
      Flight& operator=(int passengers);
      Flight& operator=(double fuel);
      Flight& operator+=(double fuel);
      Flight& operator+=(int passengers);
      Flight& operator-=(double fuel);
      Flight& operator-=(int passengers);
      Flight& operator<<(Flight& right);
      Flight& operator>>(Flight& right);
      
      //extra
      // check for the value if it is greater than the max it will set it to max and opposite for min
      int passengerCheck(int value, int min = 0, int max = Boen747Capacity);
      // check for the value if it is greater than the max it will set it to max and opposite for min
      double fuelCheck(double value, double min = 0, double max = FuelTankCapacity);
      std::ostream& display()const;
     
   };
   // helpers
   int operator+(const Flight& right, const Flight& left);
   int operator+=(int& value, const Flight& left);

}
#endif // SDDS_FLIGHT_H