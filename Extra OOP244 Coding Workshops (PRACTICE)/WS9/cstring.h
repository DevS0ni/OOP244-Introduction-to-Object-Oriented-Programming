/*************************************************************
//                      cstring Module
// File    cstring.h
// Version 1.4
// Date    
// Author  
// Description:
// Extra Classes and functions needed in the project
// -----------------------------------------------------------
*************************************************************/

#ifndef SDDS_CSTRING_H_
#define SDDS_CSTRING_H_

#include <iostream>

namespace sdds {
    class Utils {
    public:
        int strlen(const char* str);
        void strcpy(char* des, const char* src, int len = -1);
        int strcmp(const char* s1, const char* s2);
        char* alcpy(const char* cstr);
        int getInt(int low, int high);
        bool getYN();
        int getStr(char* str, bool upper);
        int stricmp(const char* s1, const char* s2);
    };
    extern Utils ut;    
}

#endif // !SDDS_CSTRING_H_
