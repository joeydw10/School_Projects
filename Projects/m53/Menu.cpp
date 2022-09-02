/* Citation and Sources...
Final Project Milestone 51
Module: Menu
Filename: Menu.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"Utils.h"
#include"Menu.h"
using namespace std;
namespace sdds {
   Menu& Menu::setEmpty()
   {
      delete[] m_menuContent;
      m_menuContent = nullptr;
      m_numOfOptions = 0;
      return *this;
   }
   Menu::Menu()
   {
      m_menuContent = nullptr;
      m_numOfOptions = 0;
   }
   Menu::Menu(unsigned numOfOptions,const char* menuContent)
   {
      if (numOfOptions <= 15 && menuContent != nullptr)
      {
         m_numOfOptions = numOfOptions;
         ut.alocpy(m_menuContent, menuContent);
      }
      else
      {
         setEmpty();
      }
   }
   Menu::~Menu()
   {
      delete[] m_menuContent;
   }
   unsigned Menu::run()
   {
      unsigned selected = 0;
      cout << m_menuContent << "0- Exit" << endl;
      cout << "> ";
      selected = ut.getint(0, m_numOfOptions);

      return selected;
   }
}