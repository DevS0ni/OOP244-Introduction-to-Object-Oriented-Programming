/*
*****************************************************************************
                              Mark.cpp
Full Name  : Dev Soni
Student ID#: 130759210
Email      : dasoni4@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Mark.h"

namespace sdds {
    Mark::Mark() : m_value(0) {}

    Mark::Mark(int value) {
        if (value >= 0 && value <= 100)
            m_value = value;
        else
            m_value = -1;
    }

    Mark::operator int() const {
        return m_value >= 0 ? m_value : 0;
    }

    Mark::operator double() const {
        return m_value >= 0 ? (m_value < 50 ? 0.0 : m_value < 60 ? 1.0 : m_value < 70 ? 2.0 : m_value < 80 ? 3.0 : 4.0) : 0.0;
    }

    Mark::operator char() const {
        return m_value >= 0 ? (m_value < 50 ? 'F' : m_value < 60 ? 'D' : m_value < 70 ? 'C' : m_value < 80 ? 'B' : 'A') : 'X';
    }

    Mark& Mark::operator+=(int value) {
        if (m_value >= 0) {
            m_value += value;
            if (m_value > 100)
                m_value = -1;
        }
        return *this;
    }

    int operator+=(int& num, const Mark& mark) {
        return (num += int(mark));
    }
}