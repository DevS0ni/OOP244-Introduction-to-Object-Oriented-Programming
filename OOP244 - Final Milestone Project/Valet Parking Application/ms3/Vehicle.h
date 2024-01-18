/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 MileStone3
-----------------------------------------------------------------------------
 */

#ifndef SDDS_VEHICLE_H_
#define SDDS_VEHICLE_H_

#include "ReadWritable.h"

namespace sdds {
    class Vehicle : public ReadWritable {
        char m_plate[9]{ '\0' };
        char* m_makeModel = nullptr;
        int m_spot = 0;
        void setEmpty();
        bool isEmpty() const;
        const char* getLicencePlate() const;
        const char* getMakeModel() const;
        int getParkingSpot() const;
    public:
        Vehicle();
        Vehicle(const char* plate, const char* mkModel);
        virtual ~Vehicle();
        Vehicle(const Vehicle& V);
        Vehicle& operator=(const Vehicle& V);
        void setMakeModel(const char* mkModel);
        void setParkingSpot(int spot);
        bool operator==(const char* plate) const;
        bool operator==(const Vehicle& V) const;
        std::istream& read(std::istream& is = std::cin);
        std::ostream& write(std::ostream& os = std::cout) const;
        virtual std::ostream& writeType(std::ostream& os) const = 0;
     };
}

#endif // !SDDS_VEHICLE_H_