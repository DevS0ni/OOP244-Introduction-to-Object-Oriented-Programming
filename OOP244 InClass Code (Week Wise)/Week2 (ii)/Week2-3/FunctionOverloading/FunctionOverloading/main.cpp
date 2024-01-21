#include <iostream>

using namespace std;

void Sum(int x, int y) {
	cout << "Sum is: " << x + y << endl;
}

void Sum(double x, double y) {
	cout << "Sum is: " << x + y << endl;
}

int main() {

	int a = 10;
	int b = 7;

	double i = 9.1;
	double j = 10.5;

	cout << "Welcome to week 2" << endl;
	
	Sum(a, b);
	Sum(i, j);




	return 0;
}

