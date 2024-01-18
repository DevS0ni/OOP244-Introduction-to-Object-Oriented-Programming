/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 Workshop 9
-----------------------------------------------------------------------------
 */

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_

#include <iostream>

namespace sdds {
    class Utils {
    public:
        // Fardads
        int strlen(const char* str);
        void strcpy(char* des, const char* src, int len = -1);
        int strcmp(const char* s1, const char* s2);
        char* alcpy(const char* cstr);
        // my functions - see Utils.cpp for more details
        int getInt(int low, int high);
        bool getYN();
        int getStr(char* str, bool upper);
        int stricmp(const char* s1, const char* s2);
    };
    extern Utils ut; // able to use utility members without 
    // withoout instantiating - Only has to
    // be done once at the beginning of 
    // Utils.cpp
}

#endif // !SDDS_UTILS_H_
