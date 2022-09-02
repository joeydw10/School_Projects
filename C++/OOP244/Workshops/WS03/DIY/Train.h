// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 2/6/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H
namespace sdds {
	const int MAX_NAME_LEN = 20;
	class Train
	{
		char tname[MAX_NAME_LEN];
		int tpeople;
		double tspeed;
	public:
		void set(const char* name , int people, double speed);
		int getNumberOfPeople() const;
		const char* getName() const;
		double getSpeed() const;
		bool isSafeEmpty() const;
		void display() const;
		bool loadPeople(int people);
		bool changeSpeed(double speed);

	};
	int transfer(Train& train1, Train& train2);

	

}
#endif // !SDDS_TRAIN_H
