/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  popReport.cpp (main)
// Version 1.0
// Date  2023/05/28
// Author   Dev Soni
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "Population.h" 
using namespace sdds;

int main() {
        if (load("PCpopulations.csv")) {
        display();
    }
    deallocateMemory();
    return 0;
}
