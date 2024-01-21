#ifndef SDDS_CAR_H
#define SDDS_CAR_H

namespace sdds {

	struct Car {
		int id;
		char* model; //char model[10];
	};

	void createCar(struct Car& mycar);

	//void displayCar(struct Car mycar); //passing by value 
	//void displayCar(struct Car* mycar);  // passing by address
	void displayCar(struct Car& mycar); // passing by reference

	void clearCar(struct Car& mycar);

}


#endif