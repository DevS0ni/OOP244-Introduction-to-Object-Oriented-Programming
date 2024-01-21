#include <iostream>
#include "Car.h"

using namespace std;
using namespace sdds;

int main() {

	int myint = 5;
	double mydouble = 9.13;
	char mychar = 'x';

	struct Car newcar = { 111,"BMW320" };

	displayCar(newcar);

	cout << "Welcome to OOP244" << endl;
	cout << "This is very early\n";
	cout << "The value is " << mydouble << endl;

	cout << "Please eneter a number:";
	cin >> myint;
	cout << "you enetered " << myint << endl;

	if (myint % 2 == 0) {
		cout << "Number is even" << endl;
	}
	else {
		cout << "Number is odd" << endl;
	}

	for (int i = 0; i <= 10; i++) {
		cout << i << ", ";
	}
	cout << endl;


	return 0;
}