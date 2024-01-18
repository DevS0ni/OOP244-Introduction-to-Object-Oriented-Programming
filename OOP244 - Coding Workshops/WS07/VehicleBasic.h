/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 Workshop 7
-----------------------------------------------------------------------------
 */

#ifndef SDDS_VEHICLEBASIC_H
#define SDDS_VEHICLEBASIC_H

#include<iostream>

namespace sdds {
    // base class
    class VehicleBasic {
        char m_plate[9]{};
        char m_location[64]{};
        int m_year = 0;
    public:
        VehicleBasic(const char* plate, int year);
        void NewAddress(const char* location);
        std::ostream& write(std::ostream& ostr = std::cout) const;
        std::istream& read(std::istream& istr);
    };
    std::ostream& operator<<(std::ostream& ostr, const VehicleBasic& V);
    std::istream& operator>>(std::istream& istr, VehicleBasic& V);
}

#endif