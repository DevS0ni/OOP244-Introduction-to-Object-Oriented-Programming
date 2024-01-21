#include <iostream>
#include "Car.h"

using namespace std;
using namespace sdds;

int main() {

	Car newcar;  // int x =0;
	Car mycar(111,"BMW");   // int x =5;
	
	createCar(newcar);
	createCar(mycar);

	displayCar(newcar);
	displayCar(mycar);

	//newcar.clearCar();
	//mycar.clearCar();
	return 0;
}