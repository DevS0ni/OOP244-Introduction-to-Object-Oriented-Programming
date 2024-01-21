#include <iostream>
#include "Car.h"

using namespace std;
using namespace sdds;

int main() {

	
	//struct Car newcar = { 111,"BMW320" }; // ok when we have fixed size model
	
	//displayCar(&newcar); // passing by addrress

	struct Car newcar;

	createCar(newcar);
	displayCar(newcar); // passing by reference

	clearCar(newcar);

	/*
	int size;
	double* grades;

	 // notes Student example
	//Student* students;
	//students = new Student[size];

	cout << "How many students do you have: ";
	cin >> size;
	grades = new double[size];
	//double grades[5];
	double average = 0;
	double sum = 0;
	cout << "Please Eneter your grades: " << endl;
	for (int i = 0; i < size; i++) {
		cout << "grade " << i + 1 << ": ";
		cin >> grades[i];
		sum += grades[i];
	}

	average = sum / size;

	cout << "AVerage is: " << average << endl;

	
	delete[] grades;
	*/

	return 0;
}