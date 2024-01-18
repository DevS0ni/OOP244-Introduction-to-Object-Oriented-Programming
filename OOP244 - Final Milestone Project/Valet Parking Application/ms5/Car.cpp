/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 MileStone5
-----------------------------------------------------------------------------
 */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Car.h"
#include "Utils.h"

using namespace std;

namespace sdds {
    Car::Car() : Vehicle() {} // default constructor
    // Constructs a Car but sets it invalid if the values passed are not vaild
    Car::Car(const char* plate, const char* mkModel) : Vehicle(plate, mkModel) {
        if (plate && mkModel) {
            int plateLen = ut.strlen(plate);
            int mkModLen = ut.strlen(mkModel);
            if (plateLen > 0 && plateLen <= 8 && mkModLen > 1 && mkModLen <= 60)
                m_valid = true;
        } else m_valid = false;
    }
    // copy constructor and assignment operator
    Car::Car(const Car& C) {
        *this = C;
    }
    // makes sure to retain the vehicle information
    Car& Car::operator=(const Car& C) {
        if (this != &C) {
            Vehicle::operator=(C); // Vekicle retains car info
            m_valid = true;
        } else m_valid = false;
        return *this;
    }
    Car::~Car() {} // empty - no dynamic members and parents are virtual
    std::ostream& Car::writeType(std::ostream& os) const {
        if (Vehicle::ReadWritable::isCsv()) os << "C,";
        else os << "Vehicle type: Car" << endl;
        return os;
    }
    // overrides and upgrades Vehicle read if a wash is wanted
    std::istream& Car::read(std::istream& is) {
        if (Vehicle::ReadWritable::isCsv()) {
            Vehicle::read(is);
            m_wash = ut.getYN(is);
            m_valid = true;
        } else {
            cout << "Car information entry" << endl;
            Vehicle::read(is);
            cout << "Carwash while parked? (Y)es/(N)o: ";
            m_wash = ut.getYN(is);
            m_valid = true;
        }
        return is;
    }
    // overrides Vehicle write to display either on screen or to a file
    std::ostream& Car::write(std::ostream& os) const {
        if (m_valid) {
            Vehicle::write(os);
            bool res = Vehicle::ReadWritable::isCsv();
            if (res)
                os << m_wash;
            else if (!res) {
                os << endl;
                if (m_wash) os << "With Carwash";
                else os << "Without Carwash";
            }
        } else {
            os << "Invalid Car Object" << endl;
        }
        return os;
    }
}
