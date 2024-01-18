#include<iostream>  // Declaration of the input/ output stream header file.
using namespace std;  // Declaration of the standarad namespace for the C++ program.
int main(void){  // Invoking the main process for the program.
    int arr[5],ind,max;  // Declaration of all the variables for this program.

    cout<<"\n\n** ARRAY : FINDING OUT THE MAXIMUM VALUE **"<<endl;  // Prompting the program header onto the console.
    cout<<"\nTaking Input..\n\n";  // Prompting to the console, to let the user know that the process is initiated for taking the user inputs, to the array.

    for(ind=0;ind<5;ind++){  // Initia
        cout<<"Enter the element for arr["<<ind<<"] : ";
        cin>>arr[ind];
    }

    cout<<"\n\n** Displaying the Array **"<<endl;

    for(ind=0;ind<5;ind++){
        cout<<"The element at arr["<<ind<<"] is : "<<arr[ind];
        cout<<endl;
    }

    cout<<"\n\n** Finding the maximum value among the elements of the array! **";

    max = arr[0];

    for(ind=0;ind<5;ind++){
        if(max<arr[ind]){
            max = arr[ind];
        }
    }

    cout<<"\n\n-> The maximum value among the elements of the array is : "<<max;

    return 0;
}