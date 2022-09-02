// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 3/16/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define  _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include "Container.h"
#include"Utils.h"
using namespace std;
namespace sdds {
   Container& Container::setEmpty()
   {
      m_content[0] = '\0';
      m_capacity = -1;
      m_cVolume = -1;
      return *this;
   }
   int Container::getCapacity()const
   {
      return m_capacity;
   }
   int Container::getVolume() const
   {
      return m_cVolume;
   }
   Container::Container()
   {
      setEmpty();
   }
   Container::Container(const char content[], const int capacity)
   {
      strcpy(m_content, content);
      m_capacity = capacity;
      m_cVolume = 0;
   }
   Container::Container(const char content[], const int capacity, const int volume)
   {
      strcpy(m_content, content);
      m_capacity = capacity;
      m_cVolume = volume;
   }
   int Container::operator+=(int value)
   {
      if ((value + m_cVolume) > m_capacity)
      {
         value = m_capacity - m_cVolume;
      }
      m_cVolume += value;

      return value;
   }
   int Container::operator-=(int value)
   {
      if (value > m_cVolume)
      {
         value = m_cVolume;
      }
      m_cVolume -= value;

      return value;
   }
   Container::operator bool()const
   {
      return m_content[0] != '\0' && m_cVolume <= m_capacity ? true : false;
   }
   Container& Container::clear(const int capacity, const char description[])
   {
      if (capacity > 0 && strlen(description) > 1)
      {
         m_capacity = capacity;
         strcpy(m_content, description);
         m_cVolume = 0;
      }
      return *this;
   }
   std::ostream& Container::print(std::ostream& ostr)const
   {
      if (*this)
      {
         ostr << m_content << ": " << "(" << m_cVolume << "cc/" << m_capacity << ")";
      }
      else
      {
         ostr << "****: (**cc/***)";
      }
      return ostr;
   }
   std::istream& Container::read(std::istream& istr)
   {
      int input;
      if (*this)
      {
         cout << "Add to " << *this << endl;
         cout << "> ";
         input = ut.getint();
         if (input > 1 && input < 220000) {
            if (input > 999)
            {
               input = 999;
            }

            cout << "Added " << (*this += input) << " CCs" << endl;
         }
      }
      else
      {
         istr.ignore();
         cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
         istr.get();
      }
      return istr;
   }
   std::ostream& operator<<(std::ostream& ostr, const Container& cc)
   {
      return cc.print(ostr);
   }
   std::istream& operator>>(std::istream& istr, Container& cc)
   {
      return cc.read(istr);
   }
}