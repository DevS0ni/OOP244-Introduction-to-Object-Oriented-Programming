/*
*****************************************************************************
                              File.h
Full Name  : Dev Soni
Student ID#: 130759210
Email      : dasoni4@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#pragma once  // This is a pre-processor directive
			  // which ensures that there is no multiple
			  // inclusions of header files in the translation unit...

// The pre-processor header directives...
#ifndef SDDS_FILE_H_  // If a macro named or not ( header file ), even so code
                      // will be executed...
#define SDDS_FILE_H_  // defines the macro, to prevent the further inclusion of
                      // the header files...

namespace sdds {
   bool openFile(const char filename[]);  // To open the data file...
   void closeFile(); // To close the data file...
   int noOfRecords(); // To read the number of records from the file...

   // TODO: Declare read prototypes
   bool read(int* empNum);  // To read employee Number from the file...
   bool read(double* empSalary); // To read employee Salary from the file...
   bool read(char empName[]);  // To read employee Name from the file...
}
#endif // !SDDS_FILE_H_ (marks the end of the code block)
       // --------------conditonally included based on the
       // --------------results of #ifndef check.
