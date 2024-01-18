/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 Workshop 1 - part 1
-----------------------------------------------------------------------------
 */

#ifndef SDDS_FILE_H
#define SDDS_FILE_H

#include <cstdio>
#include "ShoppingRec.h"

namespace sdds {

	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}

#endif