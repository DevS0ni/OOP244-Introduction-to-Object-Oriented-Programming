/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 Workshop 1 - part 1
-----------------------------------------------------------------------------
 */

#ifndef SDDS_SHOPPINGLIST_H
#define SDDS_SHOPPINGLIST_H


namespace sdds {


	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();
}

#endif
