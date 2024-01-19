//Determine the exact output of the following program. 3

#include<iostream>
using namespace std;
class Point {
public:

	Point() { cout << "Normal Constructor called" << endl; }

	Point(const Point& t) { cout << "Copy constructor called" << endl; }
};

int main()
{
	//Point p1;
	Point* t1, * t2;
	t1 = new Point();
	t2 = new Point(*t1);
	Point t3 = *t1;
	Point t4;
	t4 = t3;
	return 0;
}






/*

Normal Constructor called
Copy constructor called
Copy constructor called
Normal Constructor called


*/