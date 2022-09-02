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
#include<iostream>
#include"Utils.h"
#include"AidMan.h"
using namespace std;
namespace sdds {
   unsigned AidMan::menu()
   {
      unsigned selected = 0;
      int year;
      int month;
      int day;
      ut.getSystemDate(&year, &month, &day);
      cout << "Aid Management System Version 0.1" << endl;
      cout << "Date: " << year << "/";
      cout.width(2);
      cout.fill('0');
      cout << month << "/" << day << endl;
      cout << "Data file: ";
      if (m_fileName != nullptr)
         cout << m_fileName << endl;
      else
         cout << "No file" << endl;
      cout << "---------------------------------" << endl;
      selected = m_menu.run();

      return selected;
   }
   AidMan::AidMan() :m_menu{ 7, "1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n" }
   {
      //nothing needed here
   }
   AidMan::~AidMan()
   {
      delete[] m_fileName;
   }
   void AidMan::run()
   {
      unsigned selection{};
      do
      {
         selection = menu();

         switch (selection)
         {
         case 1:
            cout << endl << "****List Items****" << endl << endl;
            break;
         case 2:
            cout << endl << "****Add Item****" << endl << endl;
            break;
         case 3:
            cout << endl << "****Remove Item****" << endl << endl;
            break;
         case 4:
            cout << endl << "****Update Quantity****" << endl << endl;
            break;
         case 5:
            cout << endl << "****Sort****" << endl << endl;
            break;
         case 6:
            cout << endl << "****Ship Items****" << endl << endl;
            break;
         case 7:
            cout << endl << "****New/Open Aid Database****" << endl << endl;
            break;
         }

      } while (selection != 0);
      cout << "Exiting Program!" << endl;
   }
}