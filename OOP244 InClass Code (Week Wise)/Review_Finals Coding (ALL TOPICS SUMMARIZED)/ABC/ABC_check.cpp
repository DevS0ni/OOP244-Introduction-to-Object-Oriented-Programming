#include<iostream>
using namespace std;

class Test {

	int no;
public:
	virtual void display() = 0; //should not implemnent in this class because it is a PVF
	void add() { cout << "No"; }
};

class ABC :public Test {
public:
	//virtual void display2() = 0; //another PVF
	void display2() { cout << "ABC"; }//Not implementing base class PVF
};

int main() {

	Test a; //not allowed because of ABC
	ABC b;//not allowed because it became ABC
	
}