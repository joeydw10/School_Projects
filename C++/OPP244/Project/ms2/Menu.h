/* Citation and Sources...
Final Project Milestone 2
Module: Status
Filename: Status.cpp
Version 1.0
Author	Joey Walton
Revision History
-----------------------------------------------------------
Date      Reason
2022/17/3  release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_MENU_H
#define SDDS_MENU_H

namespace sdds {

	class Menu
	{
		char* m_menuContent{};
		unsigned m_numOfOptions{};

		Menu& setEmpty();
	public:
		Menu();
		Menu(unsigned numOfOptions, const char* menuContent);
		//rule of three
		Menu(const Menu& mc) = delete;
		Menu& operator=(const Menu& mc) = delete;
		~Menu();

		unsigned run();

	};

}
#endif // !SDDS_MENU_H
