// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 3/5/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "HealthCard.h"

using namespace std;
namespace sdds {
   bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const
   {
      bool res = false;
      if (name != nullptr && strlen(name) > 0 && number > 999999999 && number < 9999999999 && strlen(vCode) == 2 && strlen(sNumber) == 9)
      {
         res = true;
      }
      return res;
   }

   void HealthCard::setEmpty()
   {
      m_name = nullptr;
   }

   void HealthCard::allocateAndCopy(const char* name)
   {
      delete[] m_name;
      m_name = new char[strlen(name) + 1];
      strcpy(m_name, name);
   }

   void HealthCard::extractChar(istream& istr, char ch) const
   {
      char next = istr.peek();
      if (next == ch)
      {
         istr.ignore();
      }
      else {
         istr.ignore(1000, ch);
         istr.setstate(ios::failbit);
      }
   }

   ostream& HealthCard::printIDInfo(ostream& ostr) const
   {
      ostr << m_number << "-" << m_vCode << ", " << m_sNumber;

      return ostr;
   }

   void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[])
   {
      if (validID(name, number, vCode, sNumber) == true)
      {
         allocateAndCopy(name);
         m_number = number;
         strcpy(m_vCode, vCode);
         strcpy(m_sNumber, sNumber);
      }
      else
      {
         delete[] m_name;
         setEmpty();
      }
   }


   HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[])
   {
      set(name, number, vCode, sNumber);
   }

   HealthCard::HealthCard(const HealthCard& hc)
   {
      if (hc)
      {
         set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
      }
   }

   HealthCard& HealthCard::operator=(const HealthCard& hc)
   {
      if (this != &hc)
      {
         set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
      }
      return *this;
   }

   HealthCard::~HealthCard()
   {
      delete[] m_name;
   }

   HealthCard::operator bool() const
   {
      return m_name != nullptr ? true : false;
   }

   ostream& HealthCard::print(ostream& ostr, bool toFile) const
   {
      if (*this) {
         if (toFile)
         {
            ostr << m_name << ",";
            printIDInfo(ostr) << endl;
         }
         else {
            ostr.setf(ios::left);
            ostr << setfill('.') << setw(50) << m_name;
            printIDInfo(ostr);
         }
      }
      return ostr;
   }

   std::istream& HealthCard::read(std::istream& istr)
   {
      char tName[MaxNameLength];
      long long tNumber;
      char tVCode[3];
      char tSNumber[10];
      istr.get(tName, MaxNameLength, ',');
      extractChar(istr, ',');
      istr >> tNumber;
      extractChar(istr, '-');
      istr.get(tVCode, 3, ',');
      extractChar(istr, ',');
      istr.get(tSNumber, 10, '\n');
      extractChar(istr, '\n');
      if (!istr.fail())
      {
         set(tName, tNumber, tVCode, tSNumber);
      }
      else
      {
         istr.clear();
         istr.ignore(1000, '\n');
      }
      return istr;
   }



   std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc)
   {
      if (hc)
      {
         hc.print(ostr, false);
      }
      else
      {
         ostr << "Invalid Health Card Record";
      }

      return ostr;
   }

   std::istream& operator>>(std::istream& istr, HealthCard& hc)
   {
      return hc.read(istr);
   }

}
