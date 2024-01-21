#ifndef SDDS_CAR_H
#define SDDS_CAR_H

namespace sdds {

	class Car {
	//private: //not needed beacuse classes are private by default
		int id;
		char* model; 
	public:
		//Default contructor/ non-paprameter contructor
		Car();

		// overloaded constructor // parametrized constructor
		Car(int newid, const char* newmodel);//Car(int newid = 0, const char* newmodel = "");

		//modifiers or setters
		void changeId(int id);
		void changeModel(const char* newmodel);
		//querires or getters
		int fetchId() const;
		const char* fetchModel() const;

		//destructor
		~Car();
		//void clearCar();
	};
	//helper function
	void createCar(Car& mycar);
	void displayCar(const Car& mycar);

	

}


#endif