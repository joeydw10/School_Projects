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
#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include"Menu.h"
namespace sdds {

	class AidMan
	{

		char* m_fileName{};
		Menu m_menu{};

		unsigned menu();

	public:
		AidMan();
		AidMan(const AidMan& ac) = delete;
		AidMan& operator=(const AidMan& ac) = delete;
		~AidMan();

		void run();
	};

}
#endif // !SDDS_AIDMAN_H
