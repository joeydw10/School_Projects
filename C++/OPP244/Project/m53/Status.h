/* Citation and Sources...
Final Project Milestone 51
Module: Status
Filename: Status.h
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
#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <ostream>
namespace sdds {
   class Status
   {
      char* m_statusDesc{};
      int m_statusCode;

   public:
      Status();
      Status(const char* statusDesc);
      Status(const Status& sc);
      Status& operator=(const Status& sc);
      ~Status();
      Status& operator=(const int code);
      Status& operator=(const char* desc);
      operator int()const;
      operator const char* ()const;
      operator bool()const;
      Status& clear();
   };
   std::ostream& operator<<(std::ostream& ostr, const Status& sc);
}
#endif // !SDDS_STATUS_H
