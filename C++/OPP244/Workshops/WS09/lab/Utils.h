// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 3/31/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
#include<istream>
namespace sdds {
   const int sdds_testYear = 2022;
   const int sdds_testMon = 03;
   const int sdds_testDay = 31;
   class Utils {
      bool m_testMode = false;
   public:
      void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
      int daysOfMon(int mon, int year)const;
      void testMode(bool testmode = true);
      void alocpy(char*& destination, const char* source = nullptr);
      int getint(const char* prompt = nullptr);
      int getint(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr);
      double getDouble(const char* prompt = nullptr);
      double  getDouble(double min, double max, const char* prompt = nullptr, const char* errMes = nullptr);
      char* alcpy(const char* cstr);
      char* getDynCstr(std::istream& istr, char delim = '\n');
      int getFileLength(std::istream& is);
   };
   extern Utils ut;
}

#endif // !SDDS_UTILS_H
