/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 MileStone5
-----------------------------------------------------------------------------
 */

#ifndef SDDS_READWRITEABLE_H_
#define SDDS_READWRITEABLE_H_

#include <iostream>

namespace sdds {
    // abstract base class - not an interface bc it has implemented 
    //      functions isCsv() & setCsv()
    class ReadWritable {
        bool m_comma; // user input || read from csv file
    public:
        ReadWritable();
        virtual ~ReadWritable();
        bool isCsv() const;
        void setCsv(bool val);
        // pure virtual functions for I/O
        virtual std::istream& read(std::istream& is = std::cin) = 0;
        virtual std::ostream& write(std::ostream& os = std::cout) const = 0;
    };
    std::ostream& operator<<(std::ostream& os, ReadWritable& R);
    std::istream& operator>>(std::istream& is, ReadWritable& R);
}

#endif // !SDDS_READWRITEABLE_H_