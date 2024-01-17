 // Input Output Objects
 // inputOutput.cpp
 //
 // To compile on linux: g++ inputOutput.cpp 
 // To run compiled code: a.out
 //
 // To compile on windows:   cl welcome.cpp
 // To run compiled code: welcome
 //

 #include <iostream>
 using namespace std;

 int main() {
     int i;

     cout << "Enter an integer : ";                     // << - insertion operator = inserts data
     cin >> i;                                          // >> - extraction operator = extracts data
     cout << "You entered " << i << endl;
 }