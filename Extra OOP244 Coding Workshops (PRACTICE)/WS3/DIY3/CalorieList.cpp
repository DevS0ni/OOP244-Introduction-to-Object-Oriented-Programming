/*
*****************************************************************************
                              CalorieList.cpp
Full Name  : Dev Soni
Student ID#: 130759210
Email      : dasoni4@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include<iostream>
#include<iomanip>
#include<cstring>

#include "CalorieList.h"
#include "Food.h"

namespace sdds {
    int CalorieList::totalCal() const
    {
        int netCalories = 0;
        int ind = 0;

        for (ind = 0; ind < m_itemsAdded; ind++) {
            netCalories += m_items[ind].calories();
        }
        return netCalories;
    }
    void CalorieList::Title() const
    {
        std::cout << "+----------------------------------------------------+\n";
        if (isValid()) {
            std::cout << "|  Daily Calorie Consumption                         |\n";
        }
        else {
            std::cout << "| Invalid Calorie Consumption list                   |\n";
        }
        std::cout << "+--------------------------------+------+------------+\n";
        std::cout << "| Food name                      | Cals | When       |\n";
        std::cout << "+--------------------------------+------+------------+\n";
    }
    void CalorieList::footer() const
    { 
        std::cout << "+--------------------------------+------+------------+\n";
        if (isValid()) {
            std::cout << "|    Total Calories for today:   " << std::setw(6) << std::right << totalCal() << " |            |\n";
        }
        else {
            std::cout << "|    Invalid Calorie Consumption list                |\n";
        }
        std::cout << "+----------------------------------------------------+\n";
    }
    void CalorieList::setEmpty()
    {
        m_items = nullptr;
        m_noOfItems = 0;
        m_itemsAdded = 0;
    }
    bool CalorieList::isValid() const
    {
        bool result = true;
        int ind = 0;

        if (m_items == nullptr) {
            result = false;
        }
        for (ind = 0; ind < m_noOfItems; ind++) {
            if (!m_items[ind].isValid()) {
                result = false;
            }
        }

        return result;
    }
    void CalorieList::init(int size) {
        if (size > 0) {
            m_itemsAdded = 0;
            m_noOfItems = size;
            m_items = new Food[m_noOfItems];
            
            for (int i = 0; i < m_noOfItems; i++) {
                m_items[i].setEmpty();
            }
        }
        else {
            setEmpty();
        }
    }

    bool CalorieList::add(const char* item_name, int calories, int when) {
        bool result = false;

        if (m_items != nullptr && m_itemsAdded < m_noOfItems) {
            m_items[m_itemsAdded].set(item_name, calories, when);
            m_itemsAdded++;
            result = true;
        }
        else {
            result = false;
        }
        return result;
    }

    void CalorieList::display() const {
        Title();

        for (int ind = 0; ind < m_noOfItems; ind++) {

            m_items[ind].display();
        }

        footer();
        
    }

    void CalorieList::deallocate() {
        delete[] m_items;
        m_items = nullptr;
        m_noOfItems = 0;
        m_itemsAdded = 0;
    }
}