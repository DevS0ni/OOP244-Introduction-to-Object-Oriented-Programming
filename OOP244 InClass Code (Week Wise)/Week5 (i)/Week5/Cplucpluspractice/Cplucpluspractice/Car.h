#ifndef SDDS_CAR_H
#define SDDS_CAR_H

namespace sdds {

	class Car {
		int id;
		//char* model;
		char model[26];
		double speed = 0;
	public:
		//Default contructor/ non-paprameter contructor
		Car();

		// overloaded constructor // parametrized constructor
		Car(int newid, const char* newmodel);//Car(int newid = 0, const char* newmodel = "");

		//modifiers or setters
		void changeId(int id);
		void changeModel(const char* newmodel);
		void setSpeed(double spd);
		//querires or getters
		int fetchId() const;
		const char* fetchModel() const;
		double getSpeed() const;

		//operators
		Car& operator+=(double inc);
		operator bool() const;
		Car& operator++(); 
		Car& operator++(int);

		//destructor
		//~Car();
	};
	//helper function
	void createCar(Car& mycar);
	void displayCar(const Car& mycar);

	bool operator==(const Car& c1, const Car& c2);

	

}


#endif