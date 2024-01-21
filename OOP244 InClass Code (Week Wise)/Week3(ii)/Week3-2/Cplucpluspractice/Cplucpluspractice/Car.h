#ifndef SDDS_CAR_H
#define SDDS_CAR_H

namespace sdds {

	class Car {
	//private: //not needed beacuse classes are private by default
		int id;
		char* model; 
	public:
		//modifiers or setters
		void changeId(int newid);
		void changeModel(const char* newmodel);
		//querires or getters
		int fetchId() const;
		const char* fetchModel() const;


		void clearCar();
	};
	//helper function
	void createCar(Car& mycar);
	void displayCar(const Car& mycar);

	

}


#endif