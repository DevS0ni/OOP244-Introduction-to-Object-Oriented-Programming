/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 Workshop 8
-----------------------------------------------------------------------------
 */

#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_

#include "LblShape.h"

namespace sdds {
    // Rectangle Shape with a label
    class Rectangle : public LblShape{
        int m_width;
        int m_height;
    public:
        Rectangle();
        Rectangle(const char* label, int width, int height);
        void getSpecs(std::istream& is);
        void draw(std::ostream& os);
    };
}

#endif // !SDDS_RECTANGLE_H_


