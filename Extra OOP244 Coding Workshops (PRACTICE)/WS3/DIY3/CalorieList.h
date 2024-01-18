/*
*****************************************************************************
                              CalorieList.h
Full Name  : Dev Soni
Student ID#: 130759210
Email      : dasoni4@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_CALORIELIST_H
#define SDDS_CALORIELIST_H

#include "Food.h"

namespace sdds {

    class CalorieList {
        Food* m_items;
        int m_noOfItems;
        int m_itemsAdded;
        int totalCal()const;
        void Title()const;
        void footer()const;
        void setEmpty();
        bool isValid()const;

    public:
        void init(int size);
        bool add(const char* item_name, int calories, int when);
        void display() const;
        void deallocate();
    };

}
#endif // !SDDS_CALORIELIST_H