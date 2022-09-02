// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 2/19/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Portfolio.h"

using namespace std;
namespace sdds {


   Portfolio::Portfolio() {
      emptyPortfolio();
   }

   void Portfolio::emptyPortfolio()
   {
      m_value = 0;
      m_stock[0] = 0;
      m_type = 'E';
   }
   Portfolio::Portfolio(double value, const char* stock, char type) {
      emptyPortfolio();
      if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
         m_value = value;
         m_type = type;
         strcpy(m_stock, stock);
      }
   }

   void Portfolio::dispPortfolio() const {
      cout << " ";
      cout.width(10);
      cout << (const char*)(*this);
      cout << " | ";
      cout << "Value: ";
      cout.width(10);
      cout << double(*this);
      cout << " | ";
      cout << " Type: ";
      cout << char(*this);
   }
   std::ostream& Portfolio::display() const {

      if (~*this) {
         cout << " Portfolio  |  Bad-NG |";
         dispPortfolio();
      }
      else if (*this) {
         cout << " Portfolio  |  Active |";
         dispPortfolio();

      }
      else {
         cout << " Portfolio  |  EMPTY  |";
         dispPortfolio();
      }
      return cout;
   }

   Portfolio::operator double() const
   {
      return(double)m_value;
   }

   Portfolio::operator const char* () const
   {
      return(const char*)m_stock;
   }

   Portfolio::operator char() const
   {
      return (char)m_type;
   }

   Portfolio::operator bool() const
   {
      return m_type == 'G' || m_type == 'V' || m_type == 'I' ? true : false;
   }

   bool Portfolio::operator~() const
   {
      return m_value < 0 ? true: false;
   }

   Portfolio& Portfolio::operator+=(double value)
   {
      if (value > 0 && *this)
      {
         m_value += value;
      }
      return *this;
   }

   Portfolio& Portfolio::operator-=(double value)
   {
      if (value > 0 && *this)
      {
         m_value -= value;
      }
      return *this;
   }

   Portfolio& Portfolio::operator<<(Portfolio& right)
   {
      if (*this && right)
      {
         m_value += right.m_value;
         right.emptyPortfolio();
      }
      return *this;
   }

   Portfolio& Portfolio::operator>>(Portfolio& right)
   {
      if (*this && right)
      {
         right.m_value += m_value;
         emptyPortfolio();
      }
      return *this;
   }



   double operator+(const Portfolio& left, const Portfolio& right)
   {
      double total = 0;
      if (left && right)
      {
         total = (double)left + (double)right;
      }
      return total;
   }

   double operator+=(double& left, const Portfolio& right)
   {
      left += (double)right;
      return left;
   }

}