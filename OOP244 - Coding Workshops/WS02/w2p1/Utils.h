/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 Workshop 2 - part 1
-----------------------------------------------------------------------------
 */

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_

namespace sdds {
	int strlen(const char* str);
	// copies up to len chars from src to des
	// if len is negative, it will copy up to null char
	// resulting a cstring in des in any case
	void strcpy(char* des, const char* src, int len = -1);
	int strcmp(const char* s1, const char* s2);
}
#endif // !SDDS_UTILS_H_