// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 3/24/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include"LblShape.h"
namespace sdds {
	class Rectangle : public LblShape
	{
		int m_width = 0;
		int m_height = 0;

		operator bool()const;

	public:
		Rectangle();
		Rectangle(const char* label, const int width, const int height);
		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr)const;
	};
}
#endif // !SDDS_RECTANGLE_H
