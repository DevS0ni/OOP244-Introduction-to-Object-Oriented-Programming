#include <iostream>
using namespace std;

class Point
{
    int  x, y;
public:
   Point() {};
   Point(int i = 2, int j = 1) { x = i; y = j; }
    Point(const Point& p) { x = p.x; y = p.y; }
    int getX() { return x; }
    int getY() { return y; }
};

int main()
{
    Point p3;
    Point p1(2,5);
    Point p2 = p1;
    cout << "x = " << p2.getX()
        << ", y = " << p2.getY();
    return 0;
}








/*

No default constructor exists
*/

/*
x= 2, y= 1
*/