/*
***************************
                              Item.cpp
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
#include "Item.h"
using namespace std;
namespace sdds {
    void Item::setName(const char* name)
    {       
        strncpy(m_itemName, name, 20);
        m_itemName[20] = '\0';
    }
    void Item::setEmpty()
    {
        m_price = 0.0;
        m_itemName[0] = '\0';
        m_taxed = false;
    }
    void Item::set(const char* name, double price, bool taxed)
    {
        if (price >= 0.0 && name != nullptr) {
            setName(name);
            m_price = price;
            m_taxed = taxed;
        }
        else {
            setEmpty();
        }
    }
    void Item::display() const
    {
        if (isValid()) {
            std::cout << "| " << std::left << std::setw(20) << std::setfill('.') << m_itemName << " | ";
        
            std::cout << std::right << std::setw(7) << std::setfill(' ') << std::fixed << std::setprecision(2) << m_price << " | ";
            std::cout << std::left <<std::setw(3) << (m_taxed ? "Yes" : "No ")
                << " |" << std::endl;
        }
        else {
            std::cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << std::endl;
        }
    }
    bool Item::isValid() const
    {
        return m_itemName[0] != '\0';
    }
    double Item::price() const
    {
        return m_price;
    }
    double Item::tax() const
    {
        //double result = 0.0;

        return m_taxed ? m_price * TAXRATE : 0.0;
    }
}