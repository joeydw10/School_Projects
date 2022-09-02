/* Citation and Sources...
Final Project Milestone 51
Module: AidMan
Filename: AidMan.cpp
Version 1.0
Author	Joey Walton
Revision History
-----------------------------------------------------------
Date      Reason
2022/7/4  release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include"Utils.h"
#include"AidMan.h"
#include"Item.h"
#include"Perishable.h"
using namespace std;
namespace sdds {
   unsigned AidMan::menu()
   {
      unsigned selected = 0;
      int year{};
      int month{};
      int day{};
      ut.testMode();
      ut.getSystemDate(&year, &month, &day);
      cout << "Aid Management System" << endl;
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
      dealocate();
   }
   void AidMan::run()
   {
      unsigned selection{};
      string tempStr{};
      do
      {
         selection = menu();
         if (selection != 0 && m_fileName == nullptr)
            selection = 7;

         switch (selection)
         {
         case 1:
            cout << endl << "****List Items****" << endl;
            list();
            break;
         case 2:
            cout << endl << "****Add Item****" << endl << endl;
            // add: add function
            break;
         case 3:
            cout << endl << "****Remove Item****" << endl << endl;
            //add: remove function
            break;
         case 4:
            cout << endl << "****Update Quantity****" << endl << endl;
            //add: update function
            break;
         case 5:
            cout << endl << "****Sort****" << endl << endl;
            //add: sort function
            break;
         case 6:
            cout << endl << "****Ship Items****" << endl << endl;
            //add: ship function
            break;
         case 7:
            cout << endl << "****New/Open Aid Database****" << endl;
            save(); // save before they enter the file name
            cout << "Enter file name: ";
            cin >> tempStr;
            ut.alocpy(m_fileName, tempStr.c_str());
            load();
            break;
         }
      } while (selection != 0);
      save();
      cout << "Exiting Program!" << endl;

   }
   void AidMan::save()const
   {
      if (m_fileName != nullptr)
      {

         ofstream file(m_fileName);
         for (int i = 0; i < m_iProductItems; i++)
         {
            m_array[i]->save(file);
            file << endl;
         }
         file.close();
      }
   }
   bool AidMan::load()
   {
      string tempStr = m_fileName;
      int select = 0;
      bool res = false;
      dealocate();
      ut.alocpy(m_fileName, tempStr.c_str());
      ifstream file(m_fileName);
      if (!file)
      {
         cout << "Failed to open " << m_fileName << " for reading!" << endl;
         cout << "Would you like to create a new data file?" << endl;
         cout << "1- Yes!" << endl << "0- Exit" << endl << '>';
         file.close();
         select = ut.getint(0, 1);
         if (select == 1)
         {
            ofstream file(m_fileName);
            file.close();
         }
      }
      else
      {

         while (file)
         {
            char ch = file.peek();
            if (ch >= '1' && ch <= '3')
            {
               m_array[m_iProductItems] = new Perishable;

            }
            else if (ch >= '4' && ch <= '9')
            {
               m_array[m_iProductItems] = new Item;
            }
            else {
               file.setstate(ios::badbit);
            }
            if (m_array[m_iProductItems])
            {
               m_array[m_iProductItems]->load(file);
               m_iProductItems++;
            }
            else
            {
               delete m_array[m_iProductItems];
            }
         }
      }
      if (m_iProductItems > 0)
      {
         res = true;
         cout << m_iProductItems << " records loaded!" << endl << endl;
      }

      return res;
   }
   int AidMan::list(const char* sub_desc) {
      int select = 0;
      if (m_iProductItems > 0) {
         if (sub_desc == nullptr) {
            cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;;
            cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
            for (int i = 0; i < m_iProductItems; i++) {
               cout.setf(ios::right);
               cout << setfill(' ') << setw(4) << i + 1 << " | ";
               cout.unsetf(ios::right);
               m_array[i]->linear(true);
               cout << *m_array[i];
               cout << endl;
            }
            cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
         }
         else {
            for (int i = 0; i < m_iProductItems; i++) {
               if (*m_array[i] == sub_desc) {
                  cout << m_array[i];
               }
            }
         }
         cout << "Enter row number to display details or <ENTER> to continue:" << endl << "> ";
         cin.ignore();
         if (cin.peek() != '\n') {
            select = ut.getint(1, m_iProductItems - 1);
            for (int i = 0; i < m_iProductItems; i++) {
               if (select == i) {
                  m_array[i - 1]->linear(false);
                  m_array[i - 1]->display(cout);
                  cout << endl << endl;
               }
            }
         }
         else
         {
            cout << endl;
         }
      }
      else
         cout << "The list is empty!" << endl;
      return select;
   }
   void AidMan::dealocate()
   {
      for (int i = 0; i < m_iProductItems; i++)
      {
         delete m_array[i];
      }
      delete[] m_fileName;
      m_fileName = nullptr;
      m_iProductItems = 0;
   }
}