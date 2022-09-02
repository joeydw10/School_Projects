// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 1/26/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
namespace sdds {

	struct Car
	{
		char licensePlate[9];
		char* makeModel;
		int time;
	};

	void VBPLE_Title();
	void initialize(int allocSize);
	void deallocate(Car& C);
	bool read(Car& C);
	void print(const Car& C);
	void record(const Car& C);
	void endOfDay();

}
#endif // !SDDS_CAR_H
