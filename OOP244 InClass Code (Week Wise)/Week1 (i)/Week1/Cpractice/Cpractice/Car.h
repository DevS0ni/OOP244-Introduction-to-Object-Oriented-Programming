#ifndef CAR_H
#define CAR_H

struct Car {
	int id;
	char model[10];
};

void displayCar(struct Car mycar);

#endif