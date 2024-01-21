#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Car.h"

using namespace std;

namespace sdds {
	// passing by address
	/* 
	void displayCar(struct Car* mycar) {
		cout << "details of car are: \n";
		cout << "id: " << mycar->id << endl;
		cout << "Model: " << mycar->model << endl;
	}*/

	// passing by reference
	
	void displayCar(struct Car& mycar) {
		cout << "details of car are: \n";
		cout << "id: " << mycar.id << endl;
		cout << "Model: " << mycar.model << endl;
	}

	void createCar(struct Car& mycar) {
		char tempmodel[100];
		cout << "Please ENter details of the car: " << endl;
		cout << "id: ";
		cin >> mycar.id;

		cout << "model: ";
		cin >> tempmodel;

		mycar.model = new char[strlen(tempmodel)+1];
		strcpy(mycar.model, tempmodel);
	}


	void clearCar(struct Car& mycar) {
		delete[] mycar.model;
	}
}