// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 3/8/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define  _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include <string>
#include<cctype>
#include "Name.h"

using namespace std;
namespace sdds {
   void Name::dealloc()
   {
      delete[] m_firstName;
      m_firstName = nullptr;
      delete[] m_middleName;
      m_middleName = nullptr;
      delete[] m_lastName;
      m_lastName = nullptr;
   }
   void Name::setEmptyState()
   {
      m_firstName = nullptr;
      m_middleName = nullptr;
      m_lastName = nullptr;
   }
   void Name::set(const char* firstName)
   {
      delete[] m_firstName;
      m_firstName = new char[strlen(firstName) + 1];
      strcpy(m_firstName, firstName);
   }
   void Name::set(const char* firstName, const char* lastName)
   {
      delete[] m_firstName;
      delete[] m_middleName;
      m_firstName = new char[strlen(firstName) + 1];
      strcpy(m_firstName, firstName);
      m_lastName = new char[strlen(lastName) + 1];
      strcpy(m_lastName, lastName);
   }
   void Name::set(const char* firstName, const char* middleName, const char* lastName)
   {
      delete[] m_firstName;
      delete[] m_middleName;
      delete[] m_lastName;
      m_firstName = new char[strlen(firstName) + 1];
      strcpy(m_firstName, firstName);
      m_middleName = new char[strlen(middleName) + 1];
      strcpy(m_middleName, middleName);
      m_lastName = new char[strlen(lastName) + 1];
      strcpy(m_lastName, lastName);
   }
   Name::Name()
   {
      m_firstName = nullptr;
      m_middleName = nullptr;
      m_lastName = nullptr;
   }
   Name::Name(const char* firstName)
   {
      if (isValid(firstName))
      {
         m_firstName = new char[strlen(firstName) + 1];
         strcpy(m_firstName, firstName);
         m_middleName = nullptr;
         m_lastName = nullptr;
      }
      else
      {
         setEmptyState();
      }

   }
   Name::Name(const char* firstName, const char* lastName)
   {
      if (isValid(firstName) && isValid(lastName))
      {
         set(firstName, lastName);
         m_middleName = nullptr;
      }
      else {
         setEmptyState();
      }
   }
   Name::Name(const char* firstName, const char* middleName, const char* lastName)
   {
      if (isValid(firstName) && isValid(middleName) && isValid(lastName)) {
         set(firstName, middleName, lastName);
      }
      else
      {
         setEmptyState();
      }
   }
   Name::Name(const Name& nc)
   {
      if (nc)
      {
         if (isValid(nc.m_firstName) && isValid(nc.m_middleName) && isValid(nc.m_lastName))
         {
            set(nc.m_firstName, nc.m_middleName, nc.m_lastName);
         }
         else if (isValid(nc.m_firstName) && isValid(nc.m_lastName))
         {
            set(nc.m_firstName, nc.m_lastName);
         }
         else
         {
            set(nc.m_firstName);
         }
         
      }
   }
   Name& Name::operator=(const Name& nc)
   {
      if (this != &nc)
      {
         set(nc.m_firstName, nc.m_middleName, nc.m_lastName);
      }

      return *this;
   }
   Name::~Name()
   {
      dealloc();
   }
   bool Name::getShort()const
   {
      return isShort;
   }
   Name& Name::setShort(bool shortOnly)
   {
      if (shortOnly)
      {
         isShort = true;
      }
      return *this;
   }
   Name& Name::operator+=(const char name[])
   {
      bool space = false;
      if (isValid(name))
      {

         if (m_firstName == nullptr)
         {
            delete[] m_firstName;
            m_firstName = new char[strlen(name) + 1];
            strcpy(m_firstName, name);
         }
         else if (m_middleName == nullptr)
         {
            delete[] m_middleName;
            m_middleName = new char[strlen(name) + 1];
            strcpy(m_middleName, name);
         }
         else if (m_lastName == nullptr && m_middleName != nullptr) //!isValid(m_lastName)
         {
            delete[] m_lastName;
            m_lastName = new char[strlen(name) + 1];
            strcpy(m_lastName, name);
         }
         else if ((isValid(m_firstName) && isValid(m_middleName) && isValid(m_lastName)) || space)
         {
            dealloc();
         }
      }
      return *this;
   }
   Name::operator bool()const
   {
      return m_firstName;
   }
   std::ostream& Name::print(std::ostream& ostr, bool shortOnly) const
   {
      if (*this)
      {

         if (isValid(m_firstName) && isValid(m_middleName) && isValid(m_lastName) && shortOnly == false)
         {
            ostr << m_firstName << " " << m_middleName << " " << m_lastName;
         }
         else if (isValid(m_firstName) && isValid(m_middleName) && isValid(m_lastName) && shortOnly == true)
         {
            ostr << m_firstName << " " << m_middleName[0] << ". " << m_lastName;
         }
         else if (!isValid(m_middleName) && isValid(m_lastName))// if middle is invaild set first and last name
         {
            ostr << m_firstName << " " << m_lastName;
         }
         else if (!isValid(m_middleName) && !isValid(m_lastName))// if middle and last are not valid set only first name
         {
            ostr << m_firstName;
         }
         else if (!isValid(m_lastName))
         {
            ostr << m_firstName << " " << m_middleName;
         }
      }
      else
      {
         ostr << "Bad Name";
      }

      return ostr;
   }
   std::istream& Name::read(std::istream& istr)
   {
      string tFirstName;
      string tMiddleName;
      string tLastName;

      istr >> tFirstName;
      if (istr.peek() == ' ') {
         istr.ignore();
         istr >> tMiddleName;
         if (istr.peek() == ' ') {
            istr.ignore();
            istr >> tLastName;
            if (istr.peek() == '\n') {
               set(tFirstName.c_str(), tMiddleName.c_str(), tLastName.c_str());
            }
            else
            {
               dealloc();
            }
         }
         else
         {
            set(tFirstName.c_str(), tMiddleName.c_str());
         }
      }
      else
      {
         set(tFirstName.c_str());
      }

      return istr;
   }
   bool Name::isValid(const char name[])const//valid if not null and has no spaces true = not null 0 spaces anywhere in text
   {
      bool res = false;
      bool space = false;
      if (name != nullptr && strlen(name) > 0) { 
         for (unsigned i = 0; i < strlen(name) && space == false; i++)
         {
            if (isspace(name[i]))
            {
               space = true;
            }
         }
         if (space == false)
         {
            res = true;
         }
      }
      return res;
   }

   std::istream& operator>>(std::istream& istr, Name& nc)
   {
      nc.dealloc();

      return nc.read(istr);
   }
   ostream& operator<<(ostream& ostr, const Name& nc)
   {
      if (nc)
      {
         if (nc.getShort())
         {
            nc.print(ostr, true);
         }
         else
         {
            nc.print(ostr);
         }
      }
      else
      {
         ostr << "Bad Name";
      }

      return ostr;
   }
}