/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 Workshop 10
-----------------------------------------------------------------------------
 */

#ifndef SDDS_SEARCH_H_
#define SDDS_SEARCH_H_

#include "Collection.h"

namespace sdds {
    // T must support overload== for each type passed
    // Collection must know how to add items
    template <typename T>
    bool search(T* arr, int numElem, const char* find, 
            Collection<T>& coll) 
    {
        int count = 0;
        for (int i = 0; i < numElem; i++) 
            if (arr[i] == find) { // == overload
                coll.add(arr[i]); // Collection::add()
                count++;
            }
        // if there is no matches return false
        return count ? true : false;
    }
}

#endif // !SDDS_SEARCH_H_