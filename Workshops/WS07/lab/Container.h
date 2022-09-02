// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 3/16/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H
#include<iostream>
namespace sdds {

   class Container
   {

      char m_content[51]{};
      int m_capacity{};
      int m_cVolume{};

   protected:
      Container& setEmpty();
      int getCapacity()const;
      int getVolume()const;

   public:
      Container();
      Container(const char content[], const int capacity);
      Container(const char content[], const int capacity, const int volume);

      int operator+=(int value);
      int operator-=(int value);

      operator bool()const;

      Container& clear(const int capacity, const char description[]);

      std::ostream& print(std::ostream& ostr)const;
      std::istream& read(std::istream& istr);
   };
   std::ostream& operator<<(std::ostream& ostr, const Container& cc);
   std::istream& operator>>(std::istream& istr, Container& cc);

}
#endif // !SDDS_CONTAINER_H
