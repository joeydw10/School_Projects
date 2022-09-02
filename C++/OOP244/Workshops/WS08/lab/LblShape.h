// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 3/24/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include"Shape.h"
namespace sdds {

	class LblShape: public Shape
	{
		char* m_label = nullptr;

	protected:
		const char* label()const;

	public:
		LblShape();
		LblShape(const char* label);
		~LblShape();
		LblShape(const LblShape& lc) = delete;
		LblShape& operator=(const LblShape& lc) = delete;
		void getSpecs(std::istream& istr);


	};

}
#endif // !SDDS_LBLSHAPE_H
