// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 3/16/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include<cstring>
#include "Utils.h"
using namespace std;
namespace sdds {
   Utils ut;
   void Utils::testMode(bool testmode) {
      m_testMode = testmode;
   }
   void Utils::getSystemDate(int* year, int* mon, int* day) {
      if (m_testMode) {
         if (day) *day = sdds_testDay;
         if (mon) *mon = sdds_testMon;
         if (year) *year = sdds_testYear;
      }
      else {
         time_t t = std::time(NULL);
         tm lt = *localtime(&t);
         if (day) *day = lt.tm_mday;
         if (mon) *mon = lt.tm_mon + 1;
         if (year) *year = lt.tm_year + 1900;
      }
   }
   int Utils::daysOfMon(int month, int year)const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
      return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
   }
   void Utils::alocpy(char*& destination, const char* source){

      delete[] destination;
      destination = nullptr;
      if (source != nullptr)
      {
         destination = new char[strlen(source) + 1];
         strcpy(destination, source);
      }
   }
   int Utils::getint(const char* prompt){
      int input = 0;
      if (prompt != nullptr)
      {
         cout << prompt << endl;
      }
      while (!(cin >> input))
      {
         cin.clear();
         cin.ignore(1000, '\n');
         cout << "Invalid Integer, retry: " << endl;
      }
      return input;
   }

   int Utils::getint(int min, int max, const char* prompt, const char* errMes)
   {
      int value = 0;
      bool flag = false;
      if (prompt != nullptr)
      {
         cout << prompt << endl;
      }
      while (flag == false)
      {
         value = getint();
         if (value >= min && value <= max)
         {
            flag = true;
         }
         else
         {
            if (errMes != nullptr)
            {
               cout << errMes << ", retry: " << endl;
            }
            else {
               cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
            }
         }
      }
      
      
      return value;
   }

}