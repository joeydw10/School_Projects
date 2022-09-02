/* Citation and Sources...
Final Project Milestone 1
Module: Perishable
Filename: Perishable.h
Version 1.0
Author	Joey Walton
Revision History
-----------------------------------------------------------
Date      Reason
2022/1/4  release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE _H
#include<iostream>
#include"Item.h"
#include"Date.h"
namespace sdds {
   class Perishable : public Item
   {
      Date m_expiry{};
      char* m_handling{};

   public:
      Perishable() = default;
      Perishable(const Perishable& pc);
      Perishable& operator=(const Perishable& pc);
      ~Perishable();
      const Date& expiry()const;
      int readSku(std::istream& istr);
      std::ofstream& save(std::ofstream& ofstr)const;
      std::ifstream& load(std::ifstream& ifstr);
      std::ostream& display(std::ostream& ostr)const;
      std::istream& read(std::istream& istr);

   };
}
#endif // !SDDS_PERISHABLE_H
