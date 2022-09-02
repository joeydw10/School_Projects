// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 1/21/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_PHONE_H
#define SDDS_PHONE_H
#include <iostream>
namespace sdds {

	// runs the phone directory appication
	void phoneDir(const char* programTitle, const char* fileName);
	void goodPhoneDir(const char* programTitle, FILE* file);
	void badPhoneDir(const char* programTitle, const char* fileName);

}

#endif // !SDDS_PHONE_H
