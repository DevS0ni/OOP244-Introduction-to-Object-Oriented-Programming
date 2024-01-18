/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 MileStone4
-----------------------------------------------------------------------------
 */

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <iostream>
#include "Vehicle.h"

namespace sdds {
    // concrete car class
    class Car : public Vehicle {
        bool m_wash = false;
        bool m_valid = false;
    public:
        Car();
        Car(const char* plate, const char* mkModel);
        Car(const Car& C);
        Car& operator=(const Car& C);
        virtual ~Car();
        std::ostream& writeType(std::ostream& os) const;
        std::istream& read(std::istream& is = std::cin);
        std::ostream& write(std::ostream& os = std::cout) const;
    };
}

#endif // !SDDS_CAR_H
