#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Car.h"

using namespace std;

namespace sdds {
	
	void displayCar(const Car& mycar) {
		cout << "details of car are: \n";
		cout << "id: " << mycar.fetchId() << endl;
		cout << "Model: " << mycar.fetchModel() << endl;
	}

	void createCar(Car& mycar) {
		char tempmodel[100];
		int tempid;
		cout << "Please ENter details of the car: " << endl;
		cout << "id: ";
		cin >> tempid; 
		mycar.changeId(tempid);

		cout << "model: ";
		cin >> tempmodel;

		mycar.changeModel(tempmodel);
	}

	void Car::changeId(int newid) {
		if (newid > 0) {
			id = newid;
		}
		else {
			id = 0;
		}
	}

	void Car::changeModel(const char* newmodel) {
		if (newmodel != nullptr && newmodel[0] != '\0') {
			model = new char[strlen(newmodel) + 1];
			strcpy(model,newmodel);
		}
	}

	int Car::fetchId() const {
		return id;
	}

	const char* Car::fetchModel() const {
		return model;
	}


	void Car::clearCar() {
		delete[] model;
	}
}