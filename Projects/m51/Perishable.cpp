/* Citation and Sources...
Final Project Milestone 51
Module: Perishable
Filename: Perishable.cpp
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
#include<string>
#include<cstring>
#include"Perishable.h"
#include"Utils.h"
using namespace std;
namespace sdds {
   Perishable::Perishable(const Perishable& pc) : Item(pc)
   {
      ut.alocpy(m_handling, pc.m_handling);
      m_expiry = pc.m_expiry;
      m_sku = pc.m_sku;
      m_state = pc.m_state;
      
   }
   Perishable& Perishable::operator=(const Perishable& pc)
   {
      if (this != &pc)
      {
         ut.alocpy(m_handling, pc.m_handling);
         m_expiry = pc.m_expiry;
         m_sku = pc.m_sku;
         m_state = pc.m_state;
         Item::operator=(pc);
      }
      return *this;
   }
   Perishable::~Perishable()
   {
      delete[] m_handling;
   }
   const Date& Perishable::expiry() const
   {
      return m_expiry;
   }
   int Perishable::readSku(std::istream& istr)
   {
      cout << "SKU: ";
      m_sku = ut.getint(10000, 39999);

      return m_sku;
   }
   std::ofstream& Perishable::save(std::ofstream& ofstr) const
   {
      Date temp = m_expiry;
      
      if (m_state)
      {
         Item::save(ofstr);
         ofstr << '\t';
         if (m_handling != nullptr && strlen(m_handling) > 0)
         {
            ofstr << m_handling;
         }
         ofstr << '\t';
         ofstr << temp.formatted(false);
      }

      return ofstr;
   }
   std::ifstream& Perishable::load(std::ifstream& ifstr)
   {
      m_state.clear();
      string tstr{};
      delete[] m_handling;
      m_handling = nullptr;
      Item::load(ifstr);
      getline(ifstr, tstr, '\t');
      ut.alocpy(m_handling, tstr.c_str());
      ifstr >> m_expiry;
      ifstr.ignore();
      if (ifstr.fail())
      {
         m_state = "Input file stream read (perishable) failed!";
      }
      return ifstr;
   }
   std::ostream& Perishable::display(std::ostream& ostr) const
   {
      Date temp = m_expiry;
      if (m_state)
      {
         if (linear())
         {
            Item::display(ostr);
            if (m_handling != nullptr && strlen(m_handling) > 0)
               ostr << '*';
            else
               ostr << ' ';
            m_expiry.write(ostr);
         }
         else {
            ostr << "Perishable ";
            Item::display(ostr);
            ostr << "Expiry date: ";
            ostr << temp.formatted(true) << endl;
            if (m_handling != nullptr && strlen(m_handling) > 0)
            {
               ostr << "Handling Instructions: " << m_handling << endl;
            }
         }
      }
      else
      {
         ostr << m_state;
      }
      return ostr;
   }
   std::istream& Perishable::read(std::istream& istr)
   {
      m_state.clear();
      string temp{};
      delete[] m_handling;
      m_handling = nullptr;
      Item::read(istr);    
      cout << "Expiry date (YYMMDD): ";
      m_expiry.read(istr);
      istr.ignore();
      cout << "Handling Instructions, ENTER to skip: ";
      if (istr.peek() != '\n')
      {
         getline(istr, temp, '\n');
         ut.alocpy(m_handling, temp.c_str());
      }
      if (istr.fail())
      {
         m_state = "Perishable console date entry failed!";
      }
      return istr;
   }
}