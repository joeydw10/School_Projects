// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 2/9/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_CARINVENTORY_H
#define SDDS_CARINVENTORY_H
namespace sdds {

	class CarInventory
	{
		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;
		void resetInfo();

	public:
		CarInventory();
		CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1);
		CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
		void printInfo() const;
		bool isValid() const;
		bool isSimilarTo(const CarInventory& car) const;
		~CarInventory();
	};
	bool find_similar(CarInventory car[], const int num_cars);


}
#endif // !SDDS_CARINVENTORY_H
