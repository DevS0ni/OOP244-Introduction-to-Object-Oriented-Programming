#include <stdio.h>
#include "Car.h"

void displayCar(struct Car mycar) {
	printf("details of car are: \n");
	printf("id: %d\n", mycar.id);
	printf("Model: %s\n", mycar.model);
}