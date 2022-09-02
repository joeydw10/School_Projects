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
            cout << endl << "****Add Item****" << endl;
            addItem();
            break;
         case 3:
            cout << endl << "****Remove Item****" << endl;
            removeItem();
            break;
         case 4:
            cout << endl << "****Update Quantity****" << endl;
            updateItem();
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
         // maybe this?
         for (int i = 0; i < m_iProductItems; i++)
         {
            m_array[i]->save(file);
            file << endl;
         }
      }
   }
   bool AidMan::load()
   {
      string tempStr{};
      int select = 0;
      bool res = false;
      save(); // save before they enter the file name
      cout << "Enter file name: ";
      cin >> tempStr;
      dealocate();
      ut.alocpy(m_fileName, tempStr.c_str());
      ifstream file(m_fileName);
      if (!file)
      {
         cout << "Failed to open " << m_fileName << " for reading!" << endl;
         cout << "Would you like to create a new data file?" << endl;
         cout << "1- Yes!" << endl << "0- Exit" << endl << '>';
         select = ut.getint(0, 1);
         if (select == 1)
         {
            ofstream file(m_fileName);
            file.close();
         }
      }
      else
      {
         while (!file.eof())
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
               file.setstate(ios::failbit);
            }
            if (m_array[m_iProductItems] != nullptr)
            {
               m_array[m_iProductItems]->load(file);
               if (m_array[m_iProductItems])
               {
                  m_iProductItems++;
               }
               else
               {
                  delete m_array[m_iProductItems];
                  m_array[m_iProductItems] = nullptr;
               }
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
      int select = 0, counter = 0;
      if (m_iProductItems > 0) {
         cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;;
         cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
         if (sub_desc == nullptr) {

            for (int i = 0; i < m_iProductItems; i++) {
               cout.setf(ios::right);
               cout << setfill(' ') << setw(4) << i + 1 << " | ";
               cout.unsetf(ios::right);
               m_array[i]->linear(true);
               cout << *m_array[i];
               cout << endl;
               counter++;
            }
         }
         else {
            for (int i = 0; i < m_iProductItems; i++) {
               if (*m_array[i] == sub_desc) {
                  cout.setf(ios::right);
                  cout << setfill(' ') << setw(4) << i + 1 << " | ";
                  cout.unsetf(ios::right);
                  m_array[i]->linear(true);
                  cout << *m_array[i];
                  cout << endl;
                  counter++;
               }
            }
         }
         cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
         if (sub_desc == nullptr)
         {
            cout << "Enter row number to display details or <ENTER> to continue:" << endl << "> ";
            cin.ignore();
            if (cin.peek() != '\n') {
               select = ut.getint(1, m_iProductItems - 1);
               for (int i = 0; i < m_iProductItems; i++) {
                  if (select == i) {
                     m_array[i - 1]->linear(false);
                     m_array[i - 1]->display(cout);
                     cout << endl << endl;
                     counter = select;
                  }
               }
            }
            else
            {
               cout << endl;
            }
         }
      }
      else
         cout << "The list is empty!" << endl;
      return counter;
   }
   void AidMan::addItem()
   {
      int select{};
      int sku{};
      if (m_iProductItems <= sdds_max_num_items)
      {
         cout << "1- Perishable\n2- Non-Perishable\n-----------------\n0- Exit\n> ";
         select = ut.getint(0, 2);
         if (select == 1)
         {
            m_array[m_iProductItems] = new Perishable;

         }
         else if (select == 2)
         {
            m_array[m_iProductItems] = new Item;
         }
         else
         {
            cout << "Aborted\n";
         }
         if (m_array[m_iProductItems])
         {
            sku = m_array[m_iProductItems]->readSku(cin);
            if (search(sku) == -1)
               m_array[m_iProductItems]->read(cin);
            else {
               cout << "Sku: " << sku << " is already in the system, try updating quantity instead.\n" << endl;
               delete m_array[m_iProductItems];
            }
            m_iProductItems++;
         }
      }
      else
      {
         cout << "Database full!" << endl;
      }
   }
   int AidMan::search(int sku) const
   {
      int foundSku = -1;
      for (int i = 0; i < m_iProductItems; i++)
      {
         if (*m_array[i] == sku)
         {
            foundSku = i;
         }
      }
      return foundSku;
   }
   void AidMan::remove(int index)
   {
      if (index >= 0 && index <= sdds_max_num_items)
      {
         delete m_array[index];
         for (int i = index; i < m_iProductItems; i++)
         {
            m_array[i] = m_array[i + 1];
         }
         m_iProductItems--;
      }
   }
   void AidMan::removeItem()
   {
      char desc[50];
      int Sku{};
      int index{};
      cout << "Item description: ";
      cin >> desc;
      if (list(desc) > 0)
      {
         cout << "Enter SKU: ";
         Sku = ut.getint(10000, 99999);
         index = search(Sku);
         if (index != -1)
         {
            cout << "Following item will be removed: " << endl;
            m_array[index]->linear(false);
            cout << *m_array[index];
            cout << endl;
            cout << "Are you sure?\n1- Yes!\n0- Exit\n> ";
            if (ut.getint(0, 1) == 1)
            {
               remove(index);
               cout << "Item removed!" << endl << endl;
            }
            else
            {
               cout << "Aboarted!" << endl;
            }
         }
      }
   }
   void AidMan::updateItem()
   {
      string tempStr{};
      int sku = -1, select = -1, value = -1, index = -1;
      cout << "Item description: ";
      cin >> tempStr;
      if (list(tempStr.c_str()) > 0)
      {
         cout << "Enter SKU: ";
         sku = ut.getint(10000, 99999);
         index = search(sku);
         if (index != -1)
         {
            cout << "1- Add\n2- Reduce\n0- Exit\n> ";
            select = ut.getint(0, 2);
            if (select == 1)
            {                              
               if (m_array[index]->qtyNeeded() != m_array[index]->qty())
               {
                  cout << "Quantity to add: ";
                  value = ut.getint(1, m_array[index]->qtyNeeded());
                  *m_array[index] += value;
                  cout << value << " items added!" << endl << endl;
               }
               else
                  cout << "Quantity Needed already fulfilled!\n\n";
            }
            else if (select == 2)
            {
               
               if (m_array[index]->qty() > 0)
               {
                  cout << "Quantity to reduce: ";
                  value = ut.getint(1, m_array[index]->qty());
                  *m_array[index] -= value;
                  cout << value << " items removed!" << endl << endl;
               }
               else
                  cout << "Quantity on hand is zero!\n\n";


            }
            else
               cout << "Aborted!\n\n";
         }
         else
            cout << "SKU not found!\n";
      }
      else
         cout << "No matches found!\n";
   }
   void AidMan::dealocate()
   {
      for (int i = 0; i < m_iProductItems; i++)
      {
         delete m_array[i];
         m_array[i] = nullptr;
      }
      delete[] m_fileName;
      m_fileName = nullptr;
      m_iProductItems = 0;
   }
}