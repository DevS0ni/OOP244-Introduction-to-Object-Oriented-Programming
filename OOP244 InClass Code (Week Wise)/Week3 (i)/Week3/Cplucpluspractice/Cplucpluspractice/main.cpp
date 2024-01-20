#include <iostream>
#include "Car.h"

using namespace std;
using namespace sdds;

int main() {

	Car newcar;
	Car mycar;

	createCar(newcar);
	createCar(mycar);

	displayCar(newcar); // passing by reference
	displayCar(mycar);

	newcar.clearCar();
	mycar.clearCar();

	return 0;
}