// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 1/26/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cStrTools.h"
#include "DNA.h"

using namespace std;

namespace sdds {

	FILE* fptr = NULL;
	dnaInfo* dna = nullptr;
	int size = 4;
	int expansion = 4;
	int found;

	bool beginSearch(const char* filename)
	{
		
		fptr = fopen(filename, "r");
		if (fptr != nullptr)
		{
			cout << "DNA search program" << endl;
			dna = new dnaInfo[size];
			return true;
		}
		return false;
	}

	bool read(const char* subDNA)
	{
		int tempNum = 0;
		char tempStr[1001];
		while (fscanf(fptr, "%d,%s", &tempNum, tempStr) == 2)
		{
			if (strStr(tempStr,subDNA) != 0)
			{
				if (found >= size)
				{
					dnaInfo* temp = new dnaInfo[size + expansion];
					for (int i = 0; i < size; i++)
					{
						temp[i] = dna[i];
					}
					delete[] dna;
					dna = temp;
					size += expansion;
				}
				dna[found].dnaCode = new char[strLen(tempStr) + 1];
				strCpy(dna[found].dnaCode, tempStr);
				dna[found].id = tempNum;
				found++;

			}
		}
		if (found != 0)
		return true;
		else
		return false;
	}

	void sort()
	{
		
		//doing bubble sort this is the easiest for me to do and remember reading about it
		// temp int for me to transfer the the values of index b and s without deleting the orignal
		
		dnaInfo* temp = new dnaInfo[size];

		for (int b = 0; b < found; b++)
		{
			for (int s = b + 1; s < found; s++)
			{
				if (dna[s].id < dna[b].id) {
					temp[b] = dna[b];
					dna[b] = dna[s];
					dna[s] = temp[b];
				}
			}
		}
		delete[] temp;
	}

	void displayMatches()
	{
		cout << found << " matches found:" << endl;
		for (int i = 0; i < found; i++)
		{
			cout << i + 1 << ") " << dna[i].id << ":" << endl;
			cout << dna[i].dnaCode << endl;
			cout << "======================================================================" << endl;
		}
		
	}

	void deallocate()
	{
		for (int i = 0; i < found; i++)
		{
			delete[] dna[i].dnaCode;
			dna[i].dnaCode = nullptr;
		}
		delete[] dna;
		dna = nullptr;
		found = 0;
		rewind(fptr);

	}

	void endSearch()
	{
		cout << "DNA Search Program Closed." << endl;
		fclose(fptr);
	}


}