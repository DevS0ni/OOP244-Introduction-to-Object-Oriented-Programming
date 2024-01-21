#ifndef SDDS_CAR_H
#define SDDS_CAR_H

namespace sdds {

	class Car {
		int id;
		char* model;
		double speed = 0;
	public:
		//Default contructor/ non-paprameter contructor
		Car();

		// overloaded constructor // parametrized constructor
		Car(int newid, const char* newmodel);//Car(int newid = 0, const char* newmodel = "");

		//copy constructor
		Car(const Car& src);
		//prohibit copying
		//Car(const Car& src)  = delete;
		
		// = assignment
		Car& operator=(const Car& src);
		//prohibit assignnemnt
		//Car& operator=(const Car& src) = delete;

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
		Car operator++(int);

		void createCar(std::istream& is = std::cin);
		void displayCar(std::ostream& os = std::cout) const;

		//destructor
		~Car();
	};
	//helper function
	std::istream& operator>>(std::istream& is, Car& c);
	std::ostream& operator<<(std::ostream& os, const Car& c);

	bool operator==(const Car& c1, const Car& c2);

	

}


#endif