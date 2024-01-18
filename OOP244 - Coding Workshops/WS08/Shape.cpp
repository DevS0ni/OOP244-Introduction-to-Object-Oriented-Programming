/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 Workshop 8
-----------------------------------------------------------------------------
 */

#include <iostream>
#include "Shape.h"

using namespace std;

namespace sdds {
    Shape::~Shape() { }
    // implementation of insertion and extraction overloads
    ostream& operator<<(ostream& os, Shape& S) {
        S.draw(os);
        return os;
    }
    istream& operator>>(istream& is, Shape& S) {
        S.getSpecs(is);
        return is;
    }
}