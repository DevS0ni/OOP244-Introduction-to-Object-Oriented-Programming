#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Car.h"

using namespace std;

namespace sdds {
	
	
	Car::Car() {
		id = 0;
		//model = nullptr;
		model[0] = '\0';
		speed = 0;
	}

	Car::Car(int newid, const char* newmodel) {
		if (newid > 0 && newmodel && newmodel[0] != '\0') {
			id = newid;
			/*model = new char[strlen(newmodel) + 1];
			strcpy(model, newmodel);*/
			strncpy(model, newmodel, 25);
		}
		else {
			//*this = Car();
			id = 0;
			//model = nullptr;
			model[0] = '\0';
		}
	}
	
	void displayCar(const Car& mycar) {
		cout << "details of car are: \n";
		cout << "id: " << mycar.fetchId() << endl;
		cout << "Model: " << mycar.fetchModel() << endl;
		cout << "Speed:" << mycar.getSpeed() << endl;
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
			/*
			if (model) {
				delete[] model;
				model = nullptr;
			}

			model = new char[strlen(newmodel) + 1];
			strcpy(model,newmodel);*/
			strncpy(model, newmodel, 25);
		}
	}

	void Car::setSpeed(double spd) {
		if (spd >= 0) {
			speed = spd;
		}
		else {
			speed = 0;
		}
	}

	double Car::getSpeed() const {
		return speed;
	}

	int Car::fetchId() const {
		return id;
	}

	const char* Car::fetchModel() const {
		return model;
	}

	Car& Car::operator+=(double inc) {
		speed += inc;
		return *this;
	}

	Car::operator bool() const {
		return(id != 0 && model);
		/*
		bool ret =  false;
		if (id > 0 && model) {
			ret = true;
		}
		return ret;*/
	}

	bool operator==(const Car& c1, const Car& c2) {
		return (c1.fetchId() == c2.fetchId() && c1.getSpeed() == c2.getSpeed() && (strcmp(c1.fetchModel(),c2.fetchModel())==0));
	}



	Car& Car::operator++(int) {
		Car c = *this;
		++(*this);//speed++;
		return c;
	}

	Car& Car::operator++() {
		speed++;
		return *this;
	}

	/*
	Car::~Car() {
		cout << model << " is dying" << endl;
		delete[] model;
	}*/

}