/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 Workshop 8
-----------------------------------------------------------------------------
 */

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "LblShape.h"

namespace sdds {
    // return the label
    const char* LblShape::label() const {
        return m_label;
    }
    LblShape::LblShape() { // default constructor
        m_label = nullptr;
    }
    LblShape::LblShape(const char* label) { // set the label
        if (label) {
            m_label = new char[strlen(label) + 1];
            strcpy(m_label, label);
        }
    }
    LblShape::~LblShape() { // destruct
        delete[] m_label;
    }
    // if there is already a label delete it and set a new one
    // based on user input
    void LblShape::getSpecs(std::istream& is) {
        char label[64];
        is.getline(label, 64, ',');
        if (m_label) delete[] m_label;
        m_label = new char[strlen(label) + 1];
        strcpy(m_label, label);
    }
}