/* Citation and Sources...
Final Project Milestone 1
Module: Item
Filename: Item.h
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
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include<fstream>
#include"iProduct.h"
#include"Status.h"
namespace sdds {
   class Item : public iProduct
   {

      double m_price{};
      int m_qty{};
      int m_qtyNeeded{};
      char* m_description{};
      bool m_linear{};

      Item& set(const Item& ic);
   protected:
      Status m_state{};
      int m_sku{};
      bool linear()const;

   public:
      Item() = default;
      Item(const Item& ic);
      Item& operator=(const Item& ic);
      ~Item();
      virtual int qtyNeeded()const;
      virtual int qty()const;
      virtual operator double()const;
      virtual operator bool()const;
      virtual int operator-=(int qty);
      virtual int operator+=(int qty);
      virtual void linear(bool isLinear);
      Item& clear();
      virtual bool operator==(int sku)const;
      virtual bool operator==(const char* description)const;
      virtual std::ofstream& save(std::ofstream& ofstr)const;
      virtual std::ifstream& load(std::ifstream& ifstr);
      virtual std::ostream& display(std::ostream& ostr)const;
      virtual std::istream& read(std::istream& istr);
      virtual int readSku(std::istream& istr);
   };
}
#endif // !SDDS_ITEM_H
