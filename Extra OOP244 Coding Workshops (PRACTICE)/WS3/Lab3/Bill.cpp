/*
***************************
                             Bill.cpp
Full Name  : Dev Soni
Student ID#: 130759210
Email      : dasoni4@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Bill.h"
using namespace std;
namespace sdds {
    double Bill::totalTax() const
    {
        double netTax = 0.0;
        int ind = 0;
        for (ind = 0; ind < m_itemsAdded; ind++) {
            netTax += m_items[ind].tax();
        }
        return netTax;
    }
    double Bill::totalPrice() const
    {
        double netPrice = 0.0;
        int ind = 0;

            for (ind = 0; ind < m_itemsAdded; ind++) {
                netPrice += m_items[ind].price();
            }
        return netPrice;
    }
    void Bill::Title() const
    {
        std::cout << "+--------------------------------------+" << std::endl;

        if (isValid()) {
            std::cout << "| " << std::left << std::setw(36) << m_title << " |" << std::endl;
        }
        else {
            std::cout << "| Invalid Bill                         |" << std::endl;
        }

        std::cout << "+----------------------+---------+-----+" << std::endl;
        std::cout << "| Item Name            | Price   + Tax |" << std::endl;
        std::cout << "+----------------------+---------+-----+" << std::endl;
    }
    void Bill::footer() const
    {
        std::cout << "+----------------------+---------+-----+" << std::endl;

        if (isValid()) {
            std::cout << "|                Total Tax: " << std::right << std::setw(10) 
            << std::fixed << std::setprecision(2) << totalTax() << " |" << std::endl;
            std::cout << "|              Total Price: " << std::right << std::setw(10) 
            << std::fixed << std::setprecision(2) << totalPrice() << " |" << std::endl;
            std::cout << "|          Total After Tax: " << std::right << std::setw(10)
            << std::fixed << std::setprecision(2) 
            << totalTax() + totalPrice() << " |" << std::endl;
        }
        else {
            std::cout << "| Invalid Bill                         |" << std::endl;
        }

        std::cout << "+--------------------------------------+" << std::endl;
    }
    void Bill::setEmpty()
    {
        m_title[0] = '\0';
        m_items = nullptr;
        m_noOfItems = 0;
        m_itemsAdded = 0;
    }
    bool Bill::isValid() const
    {
        bool result = true;
        int ind = 0;

        if (m_title[0] == '\0' || m_items == nullptr) {
            result = false;
        }
        for (ind = 0; ind < m_noOfItems; ind++) {
            if (!m_items[ind].isValid()) {
                result = false;
            }
        }
      
        return result;
    }
    void Bill::init(const char* title, int noOfItems)
    {
        if (title == nullptr || noOfItems <= 0) {
            setEmpty();
        }
        else {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
                
            strncpy(m_title, title, 36);
            m_title[36] = '\0';

            m_items = new Item[m_noOfItems];

            for (int i = 0; i < m_noOfItems; i++) {
                m_items[i].setEmpty();
            }
        }
    }
    bool Bill::add(const char* item_name, double price, bool taxed)
    {
        bool result = false;

        if (m_itemsAdded < m_noOfItems) {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;
            
            result = true;
        }
        else {
            result = false;
        }
        return result;
    }

    void Bill::display() const {
        Title();

        for (int ind = 0; ind < m_noOfItems; ind++) {
            
                m_items[ind].display();
        }

        footer();
    }

    void Bill::deallocate() {
        delete[] m_items;
        m_items = nullptr;
    }
}