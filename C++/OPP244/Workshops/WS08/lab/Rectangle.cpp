// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 3/24/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include<cstring>
#include<iostream>
#include"Rectangle.h"
using namespace std;
namespace sdds {

   Rectangle::operator bool()const
   {
      return label() == nullptr || m_height == 0 || m_width == 0 ? false : true;
   }

   Rectangle::Rectangle(): LblShape()
   {
      m_width = 0;
      m_height = 0;
   }
   Rectangle::Rectangle(const char* label, const int width, const int height): LblShape(label)
   {
      m_width = width;
      m_height = height;
      if (m_height < 3 || (unsigned)m_width < strlen(LblShape::label() + 2))
      {
         m_height = 0;
         m_width = 0;
      }
   }
   void Rectangle::getSpecs(std::istream& istr)
   {
      LblShape::getSpecs(istr);
      istr >> m_width;
      istr.ignore();
      istr >> m_height;
      istr.ignore(1000, '\n');
   }
   void Rectangle::draw(std::ostream& ostr) const
   {
      if (*this)
      {
         //first line
         ostr << '+';
         ostr.fill('-');
         ostr.width(m_width - 1);
         ostr << '+' << endl;
         //second line
         ostr << '|';
         ostr.fill(' ');
         ostr.width(m_width - 2);
         ostr << left << label();
         ostr << '|' << endl;
         ostr.unsetf(ios::left);
         //third line
         for (int i = 0; i < m_height - 3; i++)
         {
            ostr << '|';
            ostr.fill();
            ostr.width(m_width - 1);    
            ostr << '|' << endl;
         }
         //end line
         ostr << '+';
         ostr.fill('-');
         ostr.width(m_width - 1);
         ostr << '+';
      }
   }
}