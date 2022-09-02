// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 3/31/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_HTMLTEXT_H
#define SDDS_HTMLTEXT_H
#include<iostream>
#include"Text.h"
namespace sdds {

	class HtmlText : public Text
	{
		char* m_title{};

	public:
		HtmlText() = default;
		HtmlText(const char* title);
		HtmlText(const HtmlText& htc);
		HtmlText& operator=(const HtmlText& htc);
		~HtmlText();
		std::ostream& write(std::ostream& ostr)const;
	};

}
#endif // !SDDS_HTMLTEXT_H
