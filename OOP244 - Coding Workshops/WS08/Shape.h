/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 Workshop 8
-----------------------------------------------------------------------------
 */

#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_

#include <iostream>

namespace sdds {
    // shape interface
    class Shape {
    public:
        virtual void draw(std::ostream& os) = 0;
        virtual void getSpecs(std::istream& is) = 0;
        virtual ~Shape();
    };
    // helper overloads - works for all children of Shape
    std::ostream& operator<<(std::ostream& os, Shape& S);
    std::istream& operator>>(std::istream& is, Shape& S);
}

#endif // !SDDS_SHAPE_H_

