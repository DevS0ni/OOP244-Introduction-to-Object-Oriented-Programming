/*
*****************************************************************************
                              Mark.h
Full Name  : Dev Soni
Student ID#: 130759210
Email      : dasoni4@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#pragma once

#ifndef SDDS_MARK_H
#define SDDS_MARK_H

namespace sdds {
    class Mark {
        int m_value;
        
    public:
        Mark();
        Mark(int mark);
        operator int() const;
        operator double() const;
        operator char() const;
        Mark& operator+=(int mark);
        
    };

    int operator+=(int& num, const Mark& mark);
}

#endif // !SDDS_MARK_H