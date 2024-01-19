#include<iostream>
using namespace std;

class Wind {

	int category;

public:

	Wind(int cat = 3) {

		category = cat;

		cout << "1." << cat << endl;

	}

	virtual void increase(int amount) {

		category += amount;

		cout << "A. " << category << endl;

	}


	virtual ~Wind() {

		cout << "C. " << category << endl;

	}

};

class Tornado :public Wind {

	double velocity;

public:

	Tornado(int cat, double vel) :Wind(cat) {

		velocity = vel;

		cout << "2. " << vel << endl;

	}

	 void increase(int value) {

		velocity += value;

		cout << "X. " << velocity << endl;

	}

	
	~Tornado() {

		cout << "Z. " << velocity << endl;

	}

};

int main() {

	Wind* wind_array[2];

	wind_array[0] = new Tornado(7, 66.5);
	
	wind_array[1] = new Wind(5);

	for (int i = 0; i < 2; i++) {

		wind_array[i]->increase(5);
	}

	for (int i = 0; i < 2; i++)

		delete wind_array[i];

	return 0;

}

/*

1.7
2. 66.5
1.5
X. 71.5
A. 10
Z. 71.5
C. 7
C. 10
*/