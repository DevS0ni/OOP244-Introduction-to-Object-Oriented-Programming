#include <iostream>
using namespace std;

class Val{

int m_val;

public:

	Val(int v) { cout << "1 agr const" << endl; m_val = v; }

  Val(const Val& V) { cout << "copy const" << endl; 
                      m_val = V.m_val - 1; }

void disp()const { cout << m_val << endl; }

};

Val foo(Val V) { 
	
	return V; }

int main() {

	//Val A(10);
	Val A = 10;
	Val B = foo(A);
	B.disp();

}

/*

1 agr const
copy const
copy const
8

*/