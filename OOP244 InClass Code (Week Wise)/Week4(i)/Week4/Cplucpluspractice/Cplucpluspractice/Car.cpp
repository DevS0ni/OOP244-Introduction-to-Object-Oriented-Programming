#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Car.h"

using namespace std;

namespace sdds {
	
	
	Car::Car() {
		id = 0;
		model = nullptr;
	}

	Car::Car(int newid, const char* newmodel) {
		if (newid > 0 && newmodel && newmodel[0] != '\0') {
			id = newid;
			model = new char[strlen(newmodel) + 1];
			strcpy(model, newmodel);
		}
		else {
			//*this = Car();
			id = 0;
			model = nullptr;
		}
	}
	
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

	void Car::changeId(int id) {
		if (id > 0) {
			this->id = id;
		}
		else {
			this->id = 0;
		}
	}

	void Car::changeModel(const char* newmodel) {

		if (newmodel != nullptr && newmodel[0] != '\0') {
			
			if (model) {
				delete[] model;
				model = nullptr;
			}

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


	Car::~Car() {
		cout << model << " is dying" << endl;
		delete[] model;
	}

	/*
	void Car::clearCar() {
		delete[] model;
	}*/
}