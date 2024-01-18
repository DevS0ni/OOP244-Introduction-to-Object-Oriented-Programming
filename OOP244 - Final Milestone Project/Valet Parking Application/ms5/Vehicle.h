/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 MileStone5
-----------------------------------------------------------------------------
 */

#ifndef SDDS_VEHICLE_H_
#define SDDS_VEHICLE_H_

#include "ReadWritable.h"

namespace sdds {
    // abstract base class Vehicle bc writeType() is pure virtual
    // to be impemented in Car and Motorcycle classes
    class Vehicle : public ReadWritable {
        char m_plate[9]{ '\0' };
        char* m_makeModel = nullptr;
        int m_spot = 0;
    protected:
        void setEmpty();
        bool isEmpty() const;
        const char* getMakeModel() const;
        void setMakeModel(const char* mkModel);
        const char* getLicencePlate() const;
    public:
        int getParkingSpot() const;
        Vehicle();
        Vehicle(const char* plate, const char* mkModel);
        virtual ~Vehicle();
        Vehicle& operator=(const Vehicle& V);
        Vehicle(const Vehicle& V);
        void setParkingSpot(int spot);
        bool operator==(const char* plate) const;
        bool operator==(const Vehicle& V) const;
        std::istream& read(std::istream& is = std::cin);
        std::ostream& write(std::ostream& os = std::cout) const;
        // will print the car or motorcycle
        virtual std::ostream& writeType(std::ostream& os) const = 0;
     };
}

#endif // !SDDS_VEHICLE_H_