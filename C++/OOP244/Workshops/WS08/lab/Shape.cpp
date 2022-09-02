// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 3/24/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include"Shape.h"
namespace sdds {
    std::ostream& operator<<(std::ostream& ostr, const Shape& sc)
    {
       sc.draw(ostr);
       return ostr;
    }
    std::istream& operator>>(std::istream& istr, Shape& sc)
    {
       sc.getSpecs(istr);
       return istr;
    }
}