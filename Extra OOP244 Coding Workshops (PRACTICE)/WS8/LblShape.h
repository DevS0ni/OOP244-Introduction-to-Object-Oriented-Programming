/*************************************************************
// File    LblShape.h
// Version 1.0
// Author  Dev Soni - dasoni4@myseneca.ca
// Description:
// LblShape Abstract class
// --------------------------------------
// Name            Date            Reason
// 
// -----------------------------------------------------------
// I have done all the coding myself and only copied the
// code provided from the course repository to complete my
// Workshop.
// -----------------------------------------------------------
*************************************************************/

#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_

#include "Shape.h"

namespace sdds {
    // class to dynamically set the label of the shape
    class LblShape : public Shape {
        char* m_label = nullptr;
    protected:
        const char* label() const;
    public:
        LblShape();
        LblShape(const char* label);
        LblShape(const LblShape&) = delete;
        LblShape& operator=(const LblShape&) = delete;
        virtual ~LblShape();
        void getSpecs(std::istream& is);
    };

}

#endif // !SDDS_LBLSHAPE_H_



