
namespace english {

     int x = 2;
     // ...

 }

 namespace french {

     int x = 3;
     // ...

 } 
 

// To access those variables :- 
#include<iostream>
// using namespace std; ---> Only write when necessary..
// using french :: x;
using namespace english;
int main(){
   // english :: x++;  --> :: (ScopeResolution)
   // french :: x--;

   // x ++; ( Only increments the french namespace's x identifier.. )

    x --;  // ( Only decrements the english namespace's x identifier.. )
}