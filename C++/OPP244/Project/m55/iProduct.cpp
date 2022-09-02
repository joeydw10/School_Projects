/* Citation and Sources...
Final Project Milestone 51
Module: iProduct
Filename: iProduct.cpp
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
#include"iProduct.h"
namespace sdds {
   std::ostream& operator<<(std::ostream& ostr, const iProduct& ipc)
   {
      return ipc.display(ostr);
   }
   std::istream& operator>>(std::istream& istr, iProduct& ipc)
   {
      return ipc.read(istr);
   }
}