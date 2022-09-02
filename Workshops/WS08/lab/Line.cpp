// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 3/24/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include<iostream>
#include"Line.h"
using namespace std;
namespace sdds {
   Line::Line(): LblShape()
   {
      m_length = 0;
   }
   Line::Line(const char* label, const int length): LblShape(label)
    {
      m_length = length;
    }
   void Line::getSpecs(std::istream& istr)
   {
      LblShape::getSpecs(istr);
      istr >> m_length;
      //istr.ignore('\n');
      istr.ignore(1000, '\n');
   }
   void Line::draw(std::ostream& ostr)const 
   {
      if (m_length > 0 && label() != nullptr)
      {
         ostr << label() << endl;
         for (int i = 0; i < m_length; i++)
         {
            ostr << '=';
         }
      }
   }
}