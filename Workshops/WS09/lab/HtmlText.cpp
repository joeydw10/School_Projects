// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 3/31/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include<iostream>
#include"HtmlText.h"
#include"Utils.h"
namespace sdds {
   HtmlText::HtmlText(const char* title) :Text()
   {
      ut.alocpy(m_title, title);

   }
   HtmlText::HtmlText(const HtmlText& htc) : Text(htc)
   {
      ut.alocpy(m_title, htc.m_title);
   }
   HtmlText& HtmlText::operator=(const HtmlText& htc)
   {
      if (this != &htc)
      {
         if (htc.m_title != nullptr)
         {
            ut.alocpy(m_title, htc.m_title);
            Text::operator=(htc);
         }

      }
      return *this;
   }
   HtmlText::~HtmlText()
   {
      delete[] m_title;
   }
   std::ostream& HtmlText::write(std::ostream& ostr) const
   {
      bool ms = false;
      char tempChar{};
      ostr << "<html><head><title>";
      if (m_title != nullptr)
      {
         ostr << m_title ;
         
      }
      else
      {
         ostr << "No Title";
      }
      ostr << "</title></head>\n<body>\n";
      if (m_title != nullptr)
      {
         ostr << "<h1>" << m_title << "</h1>\n";
      }
      
      for (int i = 0; Text::operator[](i); i++)
      {
         tempChar = Text::operator[](i);
         switch (tempChar)
         {
         case ' ':
            if (ms == true)
               ostr << "&nbsp;";
            else
               ostr << ' ';
            ms = true;
            break;
         case '<':
            ostr << "&lt;";
            ms = false;
            break;
         case '>':
            ostr << "&gt;";
            ms = false;
            break;
         case '\n':
            ostr << "<br />\n";
            ms = false;
            break;
         default:
            ostr << tempChar;
            ms = false;
            break;
         }
      }
      ostr << "</body>\n</html>";


      return ostr;
   }
}