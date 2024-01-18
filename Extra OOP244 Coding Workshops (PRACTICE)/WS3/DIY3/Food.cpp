/*
*****************************************************************************
                              Food.cpp
Full Name  : Dev Soni
Student ID#: 130759210
Email      : dasoni4@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<cstring>

#include "Food.h"

namespace sdds {
    void Food::setEmpty()
    {
        m_name[0] = '\0';
        m_calories = 0;
        m_when = 0;
    }
    void Food::set(const char* name, int calories, int when) {
        if (name != nullptr && calories >= 0 && calories <= 3000 && when >= 1 && when <= 4) {
            strncpy(m_name, name, MAX_NAME_LENGTH);
            m_name[MAX_NAME_LENGTH] = '\0';
            m_calories = calories;
            m_when = when;
        }
        else {
            m_name[0] = '\0';
            m_calories = -1;
            m_when = -1;
        }
    }

    bool Food::isValid() const
    {
        return m_name[0] != '\0';
    }

    void Food::display() const {
        if (m_name[0] != '\0' && m_calories >= 0 && m_when >= 1 && m_when <= 4) {
            std::cout << "| " << std::setw(MAX_NAME_LENGTH) << std::setfill('.') << std::left << m_name
                << " | " << std::setw(4) << std::setfill(' ') << std::right << m_calories
                << " | ";
            switch (m_when) {
            case 1:
                std::cout << "Breakfast  |\n";
                break;
            case 2:
                std::cout << "Lunch      |\n";
                break;
            case 3:
                std::cout << "Dinner     |\n";
                break;
            case 4:
                std::cout << "Snack      |\n";
                break;
            }
        }
        else {
            std::cout << "| " << std::setw(MAX_NAME_LENGTH)  << std::left << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
                << " | "  << std::setw(4)  << "xxxx"
                << " | " << std::setw(10) << "xxxxxxxxxx"
                << " |\n";
        }
    }

    int Food:: calories() const{
        return m_calories;
    }
}