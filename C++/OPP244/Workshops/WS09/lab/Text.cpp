// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 3/31/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include<cstring>
#include"Text.h"
#include"Utils.h"

using namespace std;
namespace sdds {
   const char& Text::operator[](int index) const
   {

      return m_content[index];
   }
   Text::Text(const Text& tc)
   {
      ut.alocpy(m_content, tc.m_content);

   }
   Text& Text::operator=(const Text& tc)
   {
      if (this != &tc)
      {
         if (tc.m_content != nullptr)
         {
            ut.alocpy(m_content, tc.m_content);
         }
         
      }

      return *this;
   }
   Text::~Text()
   {
      delete[] m_content;
   }
   std::istream& Text::read(std::istream& istr)
   {
      delete[] m_content;
      int len = ut.getFileLength(istr);

      m_content = new char[len + 1];
      m_content[len] = '\0';
      for (int i = 0; i < len; i++)
      {
         m_content[i] = istr.get();
      }
      if (m_content != nullptr)
      {
         
         istr.clear();
      }

      return istr;
   }
   std::ostream& Text::write(std::ostream& ostr) const
   {
      if (m_content != nullptr)
      {
         ostr << m_content;
      }

      return ostr;
   }
   istream& operator>>(istream& istr, Text& tc)
   {
      return tc.read(istr);
   }
   ostream& operator<<(ostream& ostr, const Text& tc)
   {
      return tc.write(ostr);
   }
}