// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 1/26/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_DNA_H
#define SDDS_DNA_H
namespace sdds {

	struct dnaInfo
	{
		int id;
		char* dnaCode;

	};

	bool beginSearch(const char* filename);
	bool read(const char* subDNA);
	void sort();
	void displayMatches();
	void deallocate();
	void endSearch();

}
#endif // !SDDS_DNA_H
