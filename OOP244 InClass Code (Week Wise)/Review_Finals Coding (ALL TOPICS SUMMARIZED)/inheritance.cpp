#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace  std;

class A {

    char name[10];
public:
    A( const char* nm = "Unknown") {
        strcpy(name, nm);
    }
   protected: 
    void display() const {
        cout << "Name: " << name << endl;
    }
};

class B : public A {
    int no;
public:
    B(int a=4,const char* ch="XXXX") : A(ch) {//passing arg to base class const
        no=a;
    }

    void display() const {
        A::display(); //shawdoing
        cout << no << endl;
    }
};

int main() {
    A a("XXX");
    a.display();
    B f(5,"YYY");
    f.display();
}