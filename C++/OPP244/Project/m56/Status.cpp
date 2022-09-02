/* Citation and Sources...
Final Project Milestone 51
Module: Status
Filename: Status.cpp
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
#include "Status.h"
#include"Utils.h"
namespace sdds {
   Status& Status::clear()
   {
      delete[] m_statusDesc;
      m_statusDesc = nullptr;
      m_statusCode = 0;
      return *this;
   }
   Status::Status()
   {
      m_statusDesc = nullptr;
      m_statusCode = 0;
   }
   Status::Status(const char* statusDesc)
   {
      m_statusCode = 0;
      ut.alocpy(m_statusDesc, statusDesc);

   }
   Status::Status(const Status& sc)
   {
      clear();
      if (!sc)
      {
         ut.alocpy(m_statusDesc, sc.m_statusDesc);
         m_statusCode = sc.m_statusCode;
      }
   }
   Status& Status::operator=(const Status& sc)
   {
      if (this != &sc)
      {
         ut.alocpy(m_statusDesc, sc.m_statusDesc);
         m_statusCode = sc.m_statusCode;
      }
      return *this;
   }
   Status::~Status()
   {
      delete[] m_statusDesc;
   }
   Status& Status::operator=(const int code)
   {
      m_statusCode = code;
      return *this;
   }
   Status& Status::operator=(const char* desc)
   {
      ut.alocpy(m_statusDesc, desc);
      return *this;
   }
   Status::operator int() const
   {
      return m_statusCode;
   }
   Status::operator const char* () const
   {
      return m_statusDesc;
   }
   Status::operator bool() const
   {
      return m_statusDesc == nullptr;
   }
   std::ostream& operator<<(std::ostream& ostr, const Status& sc)
   {
      if (!sc)
      {
         if (int(sc))
         {
            ostr << "ERR#" << (int)sc << ": ";
         }
         ostr << (const char*)sc;
      }

      return ostr;
   }
}