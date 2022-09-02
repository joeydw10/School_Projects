// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 3/16/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include"Utils.h"
#include"Pack.h"
using namespace std;
namespace sdds {
   //Pack::Pack()
   //{
   //   //m_packSize = -1;
   //   m_unitSize = -1;
   //   //m_numOfUnits = -1;
   //}
   Pack::Pack(const char name[], const int size, const int unitSize, const int numOfUnits) : Container(name, (size* unitSize), (numOfUnits* unitSize))
   {
      if (unitSize > 0)
      {
         m_unitSize = unitSize;
      }
      else
      {
         setEmpty();
         m_unitSize = 0;
      }

   }
   int Pack::operator+=(int unitsAdd)
   {
      int tempSize = size();
      int numOfUnits = noOfUnits();
      if ((unitsAdd + numOfUnits) > tempSize)
      {
         unitsAdd = tempSize - numOfUnits;
      }
      Container::operator+=(unitsAdd * m_unitSize);
      numOfUnits += unitsAdd;

      return unitsAdd;
   }
   int Pack::operator-=(int value)
   {
      int numOfUnits = noOfUnits();
      if (value > size())
      {
         value = size();
      }
      else if (value > numOfUnits) {
         value = numOfUnits;
      }
      Container::operator-=(value * m_unitSize);
      numOfUnits -= value;

      return value;
   }
   int Pack::unit() const
   {
      return m_unitSize;
   }
   // replaces m_numOfUnits
   int Pack::noOfUnits() const
   {

      return getVolume() / m_unitSize;
   }
   // replaces m_packSize
   int Pack::size() const
   {
      int tempSize = getCapacity();
      return tempSize / m_unitSize;
   }
   Pack& Pack::clear(const int size, const int unitSize, const char description[])
   {
      if (unitSize > 0)
      {
         Container::clear(size * unitSize, description);
         m_unitSize = unitSize;
      }
      return *this;
   }
   std::ostream& Pack::print(std::ostream& ostr) const
   {
      Container::print(ostr);
      if (*this)
      {
         ostr << ", " << noOfUnits() << " in a pack of " << size();
      }

      return ostr;
   }
   std::istream& Pack::read(std::istream& istr)
   {
      int missingUnits = 0;
      int input = 0;
      if (*this)
      {
         if (noOfUnits() < size())
         {
            missingUnits = size() - noOfUnits();
            cout << "Add to " << *this << endl;
            cout << "> ";
            input = ut.getint(1, missingUnits);
            cout << "Added " << (*this += input) << endl;
         }
         else
         {

            cout << "Pack is full!, press <ENTER> to continue...";
            istr.ignore();
            istr.get();
         }
      }
      else {
         cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
         istr.get();
      }
      return istr;
   }
   std::ostream& operator<<(std::ostream& ostr, const Pack& pc)
   {
      return pc.print(ostr);
   }
   std::istream& operator>>(std::istream& istr, Pack& pc)
   {
      return pc.read(istr);
   }
}