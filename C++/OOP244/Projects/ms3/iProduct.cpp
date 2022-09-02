/* Citation and Sources...
Final Project Milestone 1
Module: Item
Filename: Item.cpp
Version 1.0
Author	Joey Walton
Revision History
-----------------------------------------------------------
Date      Reason
3/29/2022  release
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