#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
using namespace std;
class Name{
char m_value[100];
public:

Name(const char value[]=" ") { // route 1
	strcpy(m_value, value); 
	display(); } 
Name& operator=(const char value[]) { // route 2
	strcpy(m_value, value);
	display(); 
	return *this; } 

Name& operator=(const Name& N) { // route 3
	strcpy(m_value, N.m_value);
	display(); return *this; } 

  void display() {//route 4
	  cout << "route with name "<<m_value<<" was called" << endl;
  }
};

///Which member function does the following code snippet invoke ? Why ?
int main() {
	Name G = "Homer"; //?? at the moment creating a object and assigining a value, one agrumnet const is called
	//Name N("Homer"); //same as line 25
	Name N; //??
	N = "tommy";//?? here N is already a object and we are assigning a string to 
	            //it so overloaded = will be called
	            // route 2
	G = N; //CA will be called	
}

/*

route with name Homer was called
route with name   was called
route with name tommy was called
route with name tommy was called


*/