// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 1/21/2022  
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include "Phone.h"
#include "cStrTools.h"
using namespace std;
namespace sdds {
	
	const int MAX_NAME_LENGTH = 51;
	char search[MAX_NAME_LENGTH], area[4], prefix[4], number[5];
	char name_t[MAX_NAME_LENGTH]; // name_t is a temp name for capitals 
	char name[MAX_NAME_LENGTH];
	FILE* fptr = fopen("phones.txt", "r");
	void phoneDir(const char* programTitle, const char* fileName) {
		if (strCmp(fileName,"phones.txt") == 0)
		{			
			goodPhoneDir(programTitle, fptr);
		}
		else
		{
			badPhoneDir(programTitle, fileName);
		}
		
		cout << "Thank you for using " << programTitle << " directory." << endl;
		fclose(fptr);
			
	}


	void goodPhoneDir(const char* programTitle, FILE* file) {
		cout << programTitle << " phone direcotry search" << endl;
		cout << "-------------------------------------------------------" << endl;

		do
		{
			cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
			cout << "> ";
			cin >> search;
			toLowerCaseAndCopy(search, search);// makes the text lower no matter what

			while (fscanf(file, "%[^\t]\t%s\t%s\t%s\n", name, area, prefix, number) == 4)
			{
				strCpy(name_t, name);
				toLowerCaseAndCopy(name, name);
				if (strStr(name, search) != 0)
				{
					cout << name_t << ": " << "(" << area << ") " << prefix << "-" << number << endl;
				}


			}
			rewind(fptr);// rewinds the file to the beginning
		} while (search[0] != '!');
	}
	void badPhoneDir(const char* programTitle, const char* fileName) {

		cout << "Broken Phone Book phone direcotry search" << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << fileName << " file not found!" << endl;
		
	}

}