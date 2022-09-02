// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 3/8/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_NAME_H
#define SDDS_NAME_H
#include<iostream>
namespace sdds {
   class Name
   {
      char* m_firstName{};
      char* m_middleName{};
      char* m_lastName{};
      bool isShort = false;

      void setEmptyState();
      void set(const char* firstName);
      void set(const char* firstName, const char* lastName);
      void set(const char* firstName, const char* middleName, const char* lastName);
   public:

      Name();
      Name(const char* firstName);
      Name(const char* firstName, const char* lastName);
      Name(const char* firstName, const char* middleName, const char* lastName);
      //rule of three
      Name(const Name& nc);
      Name& operator=(const Name& nc);
      ~Name();
      void dealloc();
      bool getShort()const;
      Name& setShort(bool shortOnly);
      Name& operator+=(const char name[]);
      operator bool()const;
      std::ostream& print(std::ostream& ostr, bool shortOnly = false) const;
      std::istream& read(std::istream& istr);
      //extra
      bool isValid(const char name[]) const;//checks name is vaild or not should be true if name has no spaces and is not a nullptr

   };
   std::istream& operator>>(std::istream& istr, Name& nc);
   std::ostream& operator<<(std::ostream& ostr, const Name& nc);
}
#endif // !SDDS_NAME_H
