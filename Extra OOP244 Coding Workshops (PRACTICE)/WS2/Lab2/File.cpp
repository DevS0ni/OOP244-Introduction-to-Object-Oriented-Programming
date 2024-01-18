/*
*****************************************************************************
                              File.cpp
Full Name  : Dev Soni
Student ID#: 130759210
Email      : dasoni4@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {

    // File-Pointer Global Variable...
    // File pointer used to point the datafile in the application.
   FILE* fptr;  

   // To open the datafile in the application...
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }

   // To count the number of records 
   // in the datafiles...
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }

   // To close the file in the
   // datafile application...
   void closeFile() {
      if (fptr) fclose(fptr);
   }

   // Overloaded read functions:
   // --------------------------
   // TODO: read functions go here  
   // To read different datas from the
   // data application file ('.csv') 

   // To read the Employee Number.
   bool read(int* empNum) {
       return fscanf(fptr, "%d,", empNum) == 1;
   }

   // To read the Employee Salary.
   bool read(double* empSalary) {
       return fscanf(fptr, "%lf,", empSalary) == 1;
   }

   // To read the Employee Name.
   bool read(char empName[]) {
       return fscanf(fptr, "%[^\n]\n", empName) == 1;
   } 
}