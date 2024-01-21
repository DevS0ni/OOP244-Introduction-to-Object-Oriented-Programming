#ifndef SDDS_CAR_H
#define SDDS_CAR_H

namespace sdds {

	struct Car {
		int id;
		char model[10];
	};

	void displayCar(struct Car mycar);


}


#endif