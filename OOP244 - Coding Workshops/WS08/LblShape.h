/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 Workshop 8
-----------------------------------------------------------------------------
 */

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



