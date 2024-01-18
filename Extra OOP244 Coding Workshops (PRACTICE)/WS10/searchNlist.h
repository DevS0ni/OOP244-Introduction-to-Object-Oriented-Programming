/*************************************************************
// File    searchNlist.h
// Version 1.0
// Author  dasoni4@myseneca.ca
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the
// code that my professor provided to complete my project
// milestones.
// -----------------------------------------------------------
*************************************************************/

#ifndef SEARCH_N_LIST_H
#define SEARCH_N_LIST_H

#include "Collection.h"
using namespace std;

namespace sdds{
 template <class T1, typename T2>
    bool search(Collection<T1>& coll, T1* arr, int numElem, const T2& find) {
        coll.resize(0);
        for (int i = 0; i < numElem; i++) {
            if (arr[i] == find) {
                coll.add(arr[i]);
            }
        }
        return coll.size() > 0;
    }

template <typename T>
void listArrayElements(const char* title, const T* arr, int size) {
    cout << title << endl;
    for (int i = 0; i < size; i++) {
        cout << (i + 1) << ": " << arr[i] << endl;
    }
}
}

#endif // SEARCH_N_LIST_H

/*
- Function "search" requirements:
The "search" function is a template function that allows you to search for a specific value in an array of objects and store the matching objects in a Collection. 
This function takes four arguments:
"coll": A reference to a Collection object, which will store the matching objects.
"arr": A pointer to an array of objects, where we want to search for the key value.
"numElem": The number of elements in the array.
"find": The key value we want to search for in the array.
The function goes through each element in the array and checks if it matches the key value using the "==" operator. 
-> If a match is found, the object is added to the Collection. Finally, the function returns true if at least one match is found and false if no matches are found.

- Function "listArrayElements" requirements:
The "listArrayElements" function is a template function that displays the elements of an array along with their corresponding indixes. 
This function takes three arguments:
"title": A C-style string storing the title of the list. It is displayed before the elements.
"arr": A pointer to an array of elements that we want to display.
"size": The number of elements in the array.
The function starts by displaying the title to provide context for the list then, it iterates through each element in the array, displaying the index of the element (starting from 1) followed by a colon and the element itself. Each element is displayed on a new line. 
-> This function is helpful for visually inspecting the contents of an array.*/

