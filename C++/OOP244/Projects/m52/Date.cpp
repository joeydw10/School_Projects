/* Citation and Sources...
Final Project Milestone 51
Module: Date
Filename: Date.cpp
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
#include"Date.h"
#include"Utils.h"
using namespace std;
namespace sdds {
   bool Date::validate()
   {
      bool res = true;
      int tYear = 0;
      int tMon = 0;
      int tDay = 0;
      ut.testMode(false);
      ut.getSystemDate(&tYear, &tMon, &tDay);
      if (m_year < tYear || m_year > MAXIMUM_YEAR_VALUE)
      {
         m_state = "Invalid year in date";
         m_state = 1;
         res = false;
      }
      else if (m_month < 1 || m_month > 12)
      {
         m_state = "Invalid month in date";
         m_state = 2;
         res = false;
      }
      else if (m_day < 1 || m_day > ut.daysOfMon(m_month, m_year))
      {
         m_state = "Invalid day in date";
         m_state = 3;
         res = false;
      }
      else
      {
         m_state.clear();
      }

      return res;
   }
   int Date::uniqueDateValue(const int year, const int mon, const int day)
   {
      return year * 372 + mon * 31 + day;
   }
   Date::Date()
   {
      ut.getSystemDate(&m_year, &m_month, &m_day);
      m_formatted = true;
   }
   Date::Date(const int year, const int mon, const int day)
   {
      m_year = year;
      m_month = mon;
      m_day = day;
      m_formatted = true;
      validate();
   }

   bool Date::operator==(const Date& dc)
   {
      return uniqueDateValue(m_year, m_month, m_day) == uniqueDateValue(dc.m_year, dc.m_month, dc.m_day);
   }

   bool Date::operator!=(const Date& dc)
   {
      return uniqueDateValue(m_year, m_month, m_day) != uniqueDateValue(dc.m_year, dc.m_month, dc.m_day) ? true : false;
   }

   bool Date::operator<(const Date& dc)
   {
      return uniqueDateValue(m_year, m_month, m_day) < uniqueDateValue(dc.m_year, dc.m_month, dc.m_day) ? true : false;
   }

   bool Date::operator>(const Date& dc)
   {
      return uniqueDateValue(m_year, m_month, m_day) > uniqueDateValue(dc.m_year, dc.m_month, dc.m_day) ? true : false;
   }

   bool Date::operator<=(const Date& dc)
   {
      return uniqueDateValue(m_year, m_month, m_day) <= uniqueDateValue(dc.m_year, dc.m_month, dc.m_day) ? true : false;
   }

   bool Date::operator>=(const Date& dc)
   {
      return uniqueDateValue(m_year, m_month, m_day) >= uniqueDateValue(dc.m_year, dc.m_month, dc.m_day) ? true : false;
   }

   const Status& Date::state() const
   {
      return m_state;
   }

   Date& Date::formatted(bool res)
   {
      m_formatted = res;
      return *this;
   }

   Date::operator bool() const
   {
      return m_state;
   }

   ostream& Date::write(ostream& ostr)const
   {
      if (m_formatted)
      {
         ostr << m_year << "/";
         ostr.width(2);
         ostr.fill('0');
         ostr << m_month << "/" << m_day;
      }
      else
      {
         ostr << m_year % 100;
         ostr.width(2);
         ostr.fill('0');
         ostr << m_month << m_day;
      }
      return ostr;
   }

   istream& Date::read(istream& istr)
   {
      int date = 0;
      if (istr >> date)
      {
         if (date <= 1231 )
         {
            m_day = date % 100;
            m_month = date / 100;
            ut.getSystemDate(&m_year);
         }
         else if (date > 99999 && date < 999999)
         {
            m_year = date / 10000;
            date -= m_year * 10000;
            m_year += 2000;
            m_month = date / 100;
            date -= m_month * 100;
            m_day = date;
         }
         if (validate() == false)
         {
            istr.setstate(ios::badbit);
         }
      }
      else
      {
         cout << "Invalid date value";
      }
      

      return istr;
   }

   ostream& operator<<(ostream& ostr, const Date& dc)
   {
      return dc.write(ostr);
   }

   istream& operator>>(istream& istr, Date& dc)
   {
      return dc.read(istr);
   }

}