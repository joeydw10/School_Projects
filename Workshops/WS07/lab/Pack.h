// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 3/16/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_PACK_H
#define SDDS_PACK_H
#include<iostream>
#include"Container.h"
namespace sdds {
   class Pack : public Container {
      int m_unitSize{}; // capacity of Container/ unitSize (12 cans)
      //int m_packSize{}; // size of a single item  100cc for a can   
      //int m_numOfUnits{};// volume of container/unitSize 1/12 cans etc
   public:
      //Pack();
      Pack(const char name[], const int size, const int unitSzie = 330, const int numOfUnits = 0);

      //~Pack();

      int operator+=(int unitsAdd);
      int operator-=(int value);

      // get Functions
      int unit()const; 
      int noOfUnits()const;
      int size()const;

      Pack& clear(const int size, const int unitSize, const char description[]);

      std::ostream& print(std::ostream& ostr)const;
      std::istream& read(std::istream& istr);
   };
   std::ostream& operator<<(std::ostream& ostr, const Pack& pc);
   std::istream& operator>>(std::istream& istr, Pack& pc);

}
#endif // !SDDS_PACk_H
