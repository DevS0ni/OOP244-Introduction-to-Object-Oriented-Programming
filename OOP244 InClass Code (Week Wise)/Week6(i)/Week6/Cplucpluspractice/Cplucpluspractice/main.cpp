#include <iostream>
#include "Car.h"

using namespace std;
using namespace sdds;

int main() {


	Car mycar(111,"BMW");   // int x =5;
	Car newcar;

	Car testcar(mycar);

	mycar.setSpeed(5);

	//createCar(testcar);
	//mycar.setSpeed(mycar.getSpeed() + 5);
	mycar += 5;

	if (mycar) {
		//displayCar(mycar);
		cout << mycar;
	}

	newcar = ++mycar;

	if (newcar == mycar) {
		cout << "They are the same" << endl;
	}
	else {
		cout << "They are Not the same" << endl;
	}

	newcar = mycar++;

	if (newcar == mycar) {
		cout << "They are the same" << endl;
	}else{
		cout << "They are Not the same" << endl;
	}

	
	
	return 0;
}