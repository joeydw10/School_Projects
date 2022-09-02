// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 3/24/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include"LblShape.h"
namespace sdds {

	class Line: public LblShape
	{
		int m_length = 0;
	public:
		Line();
		Line(const char* label, const int length);
		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr)const;
		
	};

}
#endif // !SDDS_LINE_H
