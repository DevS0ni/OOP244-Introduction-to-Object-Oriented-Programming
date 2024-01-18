/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 Workshop 1 - part 2
-----------------------------------------------------------------------------
 */


#ifndef SDDS_WORD_H
#define SDDS_WORD_H

using namespace std;

namespace sdds {

	const int MAX_DEFINITION_LENGTH = 1024;
	const int MAX_TYPE_LENGTH = 64;
	// word structure to be inherited into dictionary
	struct Words {
		char word[20];
		char type[MAX_TYPE_LENGTH];
		char definition[MAX_DEFINITION_LENGTH];
	};
}
#endif