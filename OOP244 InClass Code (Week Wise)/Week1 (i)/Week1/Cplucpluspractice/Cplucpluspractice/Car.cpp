#include <iostream>
#include "Car.h"

using namespace std;

namespace sdds {
	void displayCar(struct Car mycar) {
		cout << "details of car are: \n";
		cout << "id: " << mycar.id << endl;
		cout << "Model: " << mycar.model << endl;
	}
}