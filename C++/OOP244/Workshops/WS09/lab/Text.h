// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 3/31/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H
#include<iostream>
namespace sdds {
   class Text
   {
      char* m_content{};

   protected:
      const char& operator[](int index) const;

   public:
      Text() = default;
      Text(const Text& tc);
      Text& operator=(const Text& tc);
      virtual ~Text();
      std::istream& read(std::istream& istr);
      virtual std::ostream& write(std::ostream& ostr)const;
   };
   std::istream& operator>>(std::istream& istr, Text& tc);
   std::ostream& operator<<(std::ostream& ostr, const Text& tc);
}
#endif // !SDDS_TEXT_H
