// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 3/24/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include<iostream>
namespace sdds {
	class Shape
	{
	public:
		virtual void draw(std::ostream& ostr)const = 0;
		virtual void getSpecs(std::istream& istr) = 0;
		virtual ~Shape() {};

	};
	std::ostream& operator<<(std::ostream& ostr, const Shape& sc);
	std::istream& operator>>(std::istream& istr, Shape& sc);
}
#endif // !SDDS_SHAPE_H
