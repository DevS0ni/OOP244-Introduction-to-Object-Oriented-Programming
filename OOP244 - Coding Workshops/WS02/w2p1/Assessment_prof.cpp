/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 Workshop 2 - part 1
-----------------------------------------------------------------------------
 */

#define _CRT_SECURE_NO_WARNINGS

#include "Assessment.h"
#include "Utils.h"


namespace sdds {

	using namespace std;

	bool read(int& value, FILE* fptr) {
		return fscanf(fptr, "%d", &value);
	}

	bool read(double& value, FILE* fptr) {
		int res = fscanf(fptr, "%lf", &value);
		if (res != 1)
			return false; else return res;
	}

	bool read(char* title, FILE* fptr) {
		int res = fscanf(fptr, ",%60[^\n]\n", title);
		if (res != 1)
			return false; else return res;
	}

	void freeMem(Assessment*& a, int size) {
		for (int i = 0; i < size; i++) {
			delete a[i].m_mark;
			//a[i].m_mark = nullptr;
			delete a[i].m_title; //it should be delete[] a[i].m_title
			//a[i].m_title = nullptr;
		}
		delete[] a;
		a = nullptr;//added
	}

	bool read(Assessment& a, FILE* fptr) {
		double d = 0;
		char title[61];
		bool ok = false;
		int length = 0;

		if (read(d, fptr) && read(title, fptr)) ok = true;		
		if (ok) {
			// assign pointers to nullptr
			length = strlen(title);
			a.m_mark = nullptr;
			a.m_title = nullptr;

			// assign dynamic memory
			a.m_mark = new double; //can be written as double(m)
			a.m_title = new char[length]; //it should be always +1

			// assign values
			//a.m_mark = &d;
			strcpy(a.m_title, title);
			return ok;
		} else {
			return ok; //do not return multiple return statements
		}
	}
	
	int read(Assessment*& a, FILE* fptr) {
		int numValues = 0;
		int count = 0;
		bool ok = false;

		read(numValues, fptr);
		fgetc(fptr); // get \n and scrap... ready for data

		// allocate memory		
		a = new Assessment[numValues];

		// get data
		do {
			ok = read(a[count], fptr);
			if (ok) count++;
		} while (ok);

		// if it's a bad read free memory and return 0
		if (count != numValues) {
			freeMem(a, count - 1);
			return 0;
		} else {
			return count;
		}
	}
}