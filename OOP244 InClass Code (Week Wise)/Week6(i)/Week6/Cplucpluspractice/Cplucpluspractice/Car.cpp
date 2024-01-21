#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Car.h"

using namespace std;

namespace sdds {
	
	
	Car::Car() {
		id = 0;
		model = nullptr;
		speed = 0;
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

	Car::Car(const Car& src) {
		id = src.id;
		speed = src.speed;
		if (src.model != nullptr && src.model[0] != '\0') {
			model = new char[strlen(src.model) + 1];
			strcpy(model, src.model);
		}
		else {
			model = nullptr;
		}
	}

	Car& Car::operator=(const Car& src) {
		if (this != &src) {
			id = src.id;
			speed = src.speed;
			if (model) {
				delete[] model;
				model = nullptr;
			}
			if (src.model != nullptr && src.model[0] != '\0') {
				model = new char[strlen(src.model) + 1];
				strcpy(model, src.model);
			}
			else {
				model = nullptr;
			}
		}
		return *this;
	}
	
	void Car::displayCar(std::ostream& os) const{
		os << "details of car are: \n";
		os << "id: " << fetchId() << endl;
		os << "Model: " << fetchModel() << endl;
		os << "Speed:" << getSpeed() << endl;
	}

	void Car::createCar(std::istream& is) {
		char tempmodel[100];
		int tempid;
		cout << "Please ENter details of the car: " << endl;
		cout << "id: ";
		is >> tempid; 
		changeId(tempid);

		cout << "model: ";
		is >> tempmodel;

		changeModel(tempmodel);
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



	Car Car::operator++(int) {
		Car c = *this;
		++(*this);//speed++;
		return c;
	}

	Car& Car::operator++() {
		speed++;
		return *this;
	}

	std::istream& operator>>(std::istream& is, Car& c) {
		c.createCar(is);
		return is;
	}

	std::ostream& operator<<(std::ostream& os, const Car& c) {
		c.displayCar(os);
		return os;
	}

	
	Car::~Car() {
		cout << model << " is dying" << endl;
		delete[] model;
	}

}