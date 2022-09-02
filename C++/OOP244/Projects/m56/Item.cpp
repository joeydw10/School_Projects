/* Citation and Sources...
Final Project Milestone 51
Module: Item
Filename: Item.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include"Item.h"
#include"Utils.h"
using namespace std;

namespace sdds {
   Item& Item::set(const Item& ic)
   {
      if (ic.m_description != nullptr)
         ut.alocpy(m_description, ic.m_description);
      else
         m_description = nullptr;
      m_price = ic.m_price;
      m_qty = ic.m_qty;
      m_qtyNeeded = ic.m_qtyNeeded;
      m_linear = ic.m_linear;
      m_state = ic.m_state;
      m_sku = ic.m_sku;

      return *this;
   }
   bool Item::linear() const
   {
      return m_linear;
   }
   Item::Item(const Item& ic)
   {
      set(ic);

   }
   Item& Item::operator=(const Item& ic)
   {
      if (this != &ic)
      {
         set(ic);
      }
      return *this;
   }
   Item::~Item()
   {
      delete[] m_description;
   }
   int Item::qtyNeeded() const
   {
      return m_qtyNeeded;
   }
   int Item::qty() const
   {
      return m_qty;
   }
   Item::operator double() const
   {
      return m_price;
   }
   Item::operator bool() const
   {
      return m_state && m_sku > 0;
   }
   int Item::operator-=(int qty)
   {
      return m_qty -= qty;
   }
   int Item::operator+=(int qty)
   {
      return m_qty += qty;
   }
   void Item::linear(bool isLinear)
   {
      m_linear = isLinear;
   }
   Item& Item::clear()
   {
      m_state.clear();
      return *this;
   }
   bool Item::operator==(int sku) const
   {
      return m_sku == sku;
   }
   bool Item::operator==(const char* description) const
   {
      bool res = false;
      if (strstr(m_description, description) != nullptr)
      {
         res = true;
      }
      return res;
   }
   std::ofstream& Item::save(std::ofstream& ofstr)const
   {

      if (m_state)
      {
         ofstr << m_sku << "\t" << m_description << "\t" << m_qty << "\t" << m_qtyNeeded << "\t" << fixed << setprecision(2) << m_price;
      }

      return ofstr;
   }
   std::ifstream& Item::load(std::ifstream& ifstr)
   {
      m_state.clear();
      string tstr{};
      delete[] m_description;
      m_description = nullptr;

      if (!ifstr.bad())
      {
         ifstr >> m_sku;
         ifstr.ignore();
         getline(ifstr, tstr, '\t');
         ut.alocpy(m_description, tstr.c_str());
         ifstr >> m_qty;
         ifstr.ignore();
         ifstr >> m_qtyNeeded;
         ifstr.ignore();
         ifstr >> m_price;
         ifstr.ignore();
      }
      else {
         m_state = "Input file stream read failed!";
      }

      return ifstr;
   }
   std::ostream& Item::display(std::ostream& ostr)const
   {
      if (m_state)
      {
         if (linear())
         {
            ostr << setw(5) << m_sku << " | ";
            ostr << left;
            ostr.fill(' ');
            size_t len = strlen(m_description);
            if (len > 35)
            {
               for (unsigned i = 0; i < 35; i++)
               {
                  ostr << m_description[i];
               }
            }
            else
            {
               ostr << setw(35) << m_description;
            }
            ostr << " | " << right << setw(4) << m_qty << " | " << setw(4) << m_qtyNeeded << " | " << setw(7) << fixed << setprecision(2) << m_price << " |";
         }
         else
         {
            ostr << "AMA Item:" << endl;
            ostr << m_sku << ": " << m_description << endl;
            ostr << "Quantity Needed: " << m_qtyNeeded << endl;
            ostr << "Quantity Available: " << m_qty << endl;
            ostr << "Unit Price: $" << fixed << setprecision(2) << m_price << endl;
            ostr << "Needed Purchase Fund: $" << fixed << setprecision(2) << m_price * (m_qtyNeeded - m_qty) << endl;
         }
      }
      else {
         ostr << m_state;
      }
      return ostr;
   }
   int Item::readSku(std::istream& istr)
   {
      cout << "SKU: ";
      m_sku = ut.getint(40000, 99999);

      return m_sku;
   }
   std::istream& Item::read(std::istream& istr)
   {
      m_state.clear();
      string tstr{};
      delete[] m_description;
      m_description = nullptr;
      cout << "AMA Item:" << endl;
      cout << "SKU: " << m_sku << endl;
      cout << "Description: ";
      istr.clear();
      istr.ignore();
      //read Description without knowing the max
      getline(istr, tstr, '\n');
      ut.alocpy(m_description, tstr.c_str());
      cout << "Quantity Needed: ";
      //read Quantity Needed
      m_qtyNeeded = ut.getint(1, 9999);
      cout << "Quantity On Hand: ";
      // read Quantity on hand
      m_qty = ut.getint(0, m_qtyNeeded);
      cout << "Unit Price: $";
      // read Price ##.##
      m_price = ut.getDouble(0.0, 9999.0);

      if (istr.fail())
      {
         cout << "Console entry failed!";
      }

      return istr;
   }

}