/* Citation and Sources...
Final Project Milestone 51
Module: Date
Filename: Date.h
Version 1.0
Author	Joey Walton
Revision History
-----------------------------------------------------------
Date      Reason
2022/7/4  release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include<iostream>
#include"Status.h"
namespace sdds {
   const int MAXIMUM_YEAR_VALUE = 2030;
   class Date
   {
      int m_year;
      int m_month;
      int m_day;
      Status m_state;
      bool m_formatted;

      bool validate();
      int uniqueDateValue(const int year, const int mon, const int day);
   public:
      Date();
      Date(const int year, const int mon, const int day);

      bool operator==(const Date& dc);
      bool operator!=(const Date& dc);
      bool operator<(const Date& dc);
      bool operator>(const Date& dc);
      bool operator<=(const Date& dc);
      bool operator>=(const Date& dc);

      const Status& state()const;
      Date& formatted(bool res);
      operator bool()const;


      std::ostream& write(std::ostream& ostr)const;
      std::istream& read(std::istream& istr);
   };
   std::ostream& operator<<(std::ostream& ostr, const Date& dc);
   std::istream& operator>>(std::istream& istr,  Date& dc);
}
#endif // !SDDS_DATE_H
