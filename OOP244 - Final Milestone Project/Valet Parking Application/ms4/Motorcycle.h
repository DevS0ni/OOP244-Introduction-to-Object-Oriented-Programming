/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 MileStone4
-----------------------------------------------------------------------------
 */

#ifndef SDDS_MOTORCYCLE_H
#define SDDS_MOTORCYCLE_H

#include <iostream>
#include "Vehicle.h"

namespace sdds {
    // concrete class Motorcycle
    class Motorcycle : public Vehicle {
        bool m_sidecar = false;
        bool m_valid = false; // added for validity
    public:
        Motorcycle();
        Motorcycle(const char* plate, const char* mkModel);
        Motorcycle(const Motorcycle& M);
        Motorcycle& operator=(const Motorcycle& M);
        virtual ~Motorcycle();
        std::ostream& writeType(std::ostream& os) const;
        std::istream& read(std::istream& is = std::cin);
        std::ostream& write(std::ostream& os = std::cout) const;
    };
}

#endif // !SDDS_MOTORCYCLE_H
