/* Citation and Sources...
Final Project Milestone 54
Module: AidMan
Filename: AidMan.cpp
Version 1.0
Author	Joey Walton
Revision History
-----------------------------------------------------------
Date      Reason
2022/9/4  release added update quantity
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include<fstream>
#include"Menu.h"
#include"iProduct.h"
namespace sdds {

	const int sdds_max_num_items = 100;

	class AidMan
	{

		char* m_fileName{};
		Menu m_menu{};
		iProduct* m_array[sdds_max_num_items]{};// array for holding iProducts max of sdds_max_num_items
		int m_iProductItems{};// tracker for how many items are in the m_array

		unsigned menu();
		void dealocate();

	public:
		AidMan();
		AidMan(const AidMan& ac) = delete;
		AidMan& operator=(const AidMan& ac) = delete;
		virtual ~AidMan();
		void run();

		void save()const;
		bool load();
		//option 1 list
		int list(const char* sub_desc = nullptr);
		//option 2 add
		void addItem();
		int search(int sku)const;
		//option 3 remove
		void remove(int index);
		void removeItem();
		//option 4 update Quantity
		void updateItem();
		
	};

}
#endif // !SDDS_AIDMAN_H
