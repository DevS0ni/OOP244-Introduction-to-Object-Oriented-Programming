/*************************************************************
// File    LblShape.h
// Version 1.0
// Author  Dev Soni - dasoni4@myseneca.ca
// Description:
// Line class implimentation
// --------------------------------------
// Name            Date            Reason
// 
// -----------------------------------------------------------
// I have done all the coding myself and only copied the
// code provided from the course repository to complete my
// Workshop.
// -----------------------------------------------------------
*************************************************************/

#include <cstring>
#include "Line.h"

namespace sdds {
    Line::Line() { // default - set empty
        m_length = 0;
    }
    // create a line with a label
    Line::Line(const char* label, int length)
        : LblShape(label) 
    {
        m_length = length;
    }
    // get the label and length from user
    void Line::getSpecs(std::istream& is) {
        LblShape::getSpecs(is);
        is >> m_length;
        is.ignore(1000, '\n');
    }
    // output the label and line
    void Line::draw(std::ostream& os) {
        if (LblShape::label() && m_length > 0) {
            os << LblShape::label() << "\n";
            for (int i = 0; i < m_length; os << "=", i++);
        }
    }
}
