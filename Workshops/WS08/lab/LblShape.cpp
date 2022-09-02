// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 3/24/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define  _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<string>
#include"LblShape.h"
using namespace std;
namespace sdds {
   LblShape::LblShape() 
   {
      m_label = nullptr;
   }
   const char* LblShape::label() const
   {
      return m_label;
   }
   LblShape::LblShape(const char* label)
   {
      delete[] m_label;
      m_label = new char[strlen(label) + 1];
      strcpy(m_label, label);
   }
   LblShape::~LblShape()
   {
      delete[] m_label;
   }
   void LblShape::getSpecs(std::istream& istr)
   {
      string tempstr{};
      getline(istr, tempstr, ',');
      delete[] m_label;
      m_label = new char[strlen(tempstr.c_str()) + 1];
      strcpy(m_label, tempstr.c_str());
   }
}