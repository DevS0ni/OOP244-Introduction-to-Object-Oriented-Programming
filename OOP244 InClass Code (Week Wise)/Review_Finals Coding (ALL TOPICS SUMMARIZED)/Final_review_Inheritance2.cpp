//4)	What does protected access modifier means here in the following code when base class is inherited publicly by derived class.

// base class 
#include<iostream>
using namespace std;

class Parent
{   
protected:
    int id_protected;
    void display() { cout << id_protected; }
};

// derived class 
class Child : private Parent
{
public:
    void setId(int id) {
        id_protected = id;
    }
    void display2() { 
    Parent::display();
    }
};

    int main() {
        Parent p;
        p.display();
        Child c;  
        c.setId(25);
        c.display();
        c.display2();        
    }