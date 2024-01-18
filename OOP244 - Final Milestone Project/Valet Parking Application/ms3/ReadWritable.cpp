/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 MileStone3
-----------------------------------------------------------------------------
 */

#include "ReadWritable.h"

namespace sdds {
    ReadWritable::ReadWritable() {
        m_comma = false;
    }
    ReadWritable::~ReadWritable() { }
    bool ReadWritable::isCsv() const {
        return m_comma;
    }
    void ReadWritable::setCsv(bool val) {
        m_comma = val;
    }
    std::ostream& operator<<(std::ostream& os, ReadWritable& R) {
        R.write(os);
        return os;
    }
    std::istream& operator>>(std::istream& is, ReadWritable& R) {
        R.read(is);
        return is;
    }
}