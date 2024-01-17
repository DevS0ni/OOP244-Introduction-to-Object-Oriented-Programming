 // ERROR - SEGMENTATION FAULT ( C++ provides us the opportunity to avoid this by forcing us to mention the parameters in the 
 //         prototypes of the functions )

 /*
 #include <stdio.h>
 void foo();  ---> prototype arguments should be mentioned ! 

 int main(void)
 {
     foo(-25);
 }
 void foo(char x[])
 {
     printf("%s", x); ---> ERROR !!
 }
 */

#include <stdio.h>
 void foo(char x[]);  // Mentioning the parameters in the prototype, 
                      // helps us to avoid segmentation faults during the compile time. However, creates run-time error.
 int main(void)
 {
     foo(-25);        // int type (negative) = -25 
 }
 void foo(char x[])   // char * type - character pointer = looking for the address! 
 {
     printf("%s", x);
 }