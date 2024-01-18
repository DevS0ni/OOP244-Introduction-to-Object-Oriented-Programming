/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 Workshop 8
-----------------------------------------------------------------------------
 */

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
            os << LblShape::label();
            for (int i = 0; i < m_length - 
                int(strlen(LblShape::label())); os << "=", i++);
        }
    }
}
