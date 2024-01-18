/*
*****************************************************************************
							  Utils.h
Full Name  : Dev Soni
Student ID#: 130759210
Email      : dasoni4@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
namespace sdds {
	void flushkeys();
	bool ValidYesResponse(char ch);
	bool yes();
	void readCstr(char cstr[], int len);
	int readInt(int min, int max);
}

#endif //!SDDS_UTILS_H
