// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 3/31/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_TEMPS_H
#define SDDS_TEMPS_H

#include<ostream>
#include"Collection.h"
namespace sdds {
   // obj is for whatever class you are using 
   // it needs a array of the obj followed by an int for the size of the array and then a obj& for what you are trying to find
   template <typename obj>
   Collection<obj> select(const obj arr[] , int size, const obj& search) {

      int found{};
      for (int i = 0; i < size; i++)
      {
         if (arr[i] == search)
         {
            found++;
         }
      }
      Collection<obj> temp(found);
      int index = 0;
      for (int i = 0; i < size; i++)
      {
         if (arr[i] == search)
         {
            temp[index] = arr[i];
            index++;
         }
      }
      return temp;
   }
   // obj is used for making an reference of the obj
   // all this function needs is a const Collection obj& and a const char* for the title of the program you will be using it for
   template<typename obj>
   void printCollection(const Collection<obj>& objectRef, const char* title) {
      std::cout << title << std::endl;
      for (int i = 0; i < objectRef.size(); i++)
      {
         std::cout << objectRef[i] << std::endl;
      }
   }
}

#endif // !SDDS_TEMPS_H

