/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 Workshop 7
-----------------------------------------------------------------------------
 */

#ifndef SDDS_DUMPER_H
#define SDDS_DUMPER_H

#include <iostream>
#include "VehicleBasic.h"

namespace sdds {
    // derived class
    class Dumper : public VehicleBasic {
        double m_capacity;
        double m_load = 0;
    public:
        Dumper(const char* plate, int year, double capacity, 
            const char* location);
        bool loaddCargo(double load);
        bool unloadCargo();
        std::ostream& write(std::ostream& ostr = std::cout) const;
        std::istream& read(std::istream& istr);
    };
    std::ostream& operator<<(std::ostream& ostr, const Dumper& D);
    std::istream& operator>>(std::istream& istr, Dumper& D);
}
#endif