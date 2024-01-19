#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Car.h"


int main() {

	int myint = 5;
	double mydouble = 9.13;
	char mychar = 'x';

	struct Car newcar = { 111,"BMW320" };

	displayCar(newcar);


	printf("Welcome to OOP244\n");
	printf("This is very early\n");

	printf("The value is %lf\n", mydouble);

	printf("Please eneter a whole number:");
	scanf("%d", &myint);
	printf("value you enetered is: %d\n", myint);

	if (myint % 2 == 0) {
		printf("Number is even\n");
	}
	else{
		printf("Number is odd\n");
	}

	for (int i = 0; i <= 10; i++) {
		printf("%d, ", i);
	}
	printf("\n");

	return 0;
}