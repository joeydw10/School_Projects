// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 2/19/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>
#include <string>

namespace sdds {

   class Portfolio {
      double m_value = 0;
      char m_stock[16];
      char m_type;

   public:
      Portfolio();
      Portfolio(double value, const char* stock, char type);
      void emptyPortfolio();
      void dispPortfolio() const;
      std::ostream& display() const;
      // Type Conversions
      operator double() const;
      operator const char*() const;
      operator char() const;
      operator bool() const;
      // Unary
      bool operator~() const;
      // Binary
      Portfolio& operator+=(double value);
      Portfolio& operator-=(double value);
      Portfolio& operator<<(Portfolio& right);
      Portfolio& operator>>(Portfolio& right);
   };
   // Binary Helpers
   double operator+(const Portfolio& left, const Portfolio& right);
   double operator+=(double& left, const Portfolio& right);
}
#endif // SDDS_Portfolio_H_