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
#include "Motorcycle.h"
#include "Utils.h"

using namespace std;

namespace sdds {
    // constructors
    Motorcycle::Motorcycle() : Vehicle() {}
    // ensure only valid plate and mkModel are passed
    Motorcycle::Motorcycle(const char* plate, const char* mkModel)
        : Vehicle(plate, mkModel) {
        if (plate && mkModel) {
            int plateLen = ut.strlen(plate);
            int mkModLen = ut.strlen(mkModel);
            if (plateLen > 0 && mkModLen > 1 && plateLen <= 8)
                m_valid = true;
        } else m_valid = false;
    }
    // copy constructor and assignment operator
    Motorcycle::Motorcycle(const Motorcycle& M) {
        *this = M;
    }
    Motorcycle& Motorcycle::operator=(const Motorcycle& M) {
        if (this != &M) {
            Vehicle::operator=(M); // make sure vehicle information is retained
            m_valid = true;
        } else m_valid = false;
        return *this;
    }
    Motorcycle::~Motorcycle() {} // does not have any dynamic members
    // implimented writeType from ReadWriteable
    //      displays heading on console or M, in a file
    std::ostream& Motorcycle::writeType(std::ostream& os) const {
        // write based on what csv of ReadWritable is
        if (Vehicle::ReadWritable::isCsv()) os << "M,";
        else os << "Vehicle type: Motorcycle" << endl;
        return os;
    }
    // overrides Vehicle read in order to add 
    // more information about a motorcycle i.e sidecar
    std::istream& Motorcycle::read(std::istream& is) {
        if (Vehicle::ReadWritable::isCsv()) {
            Vehicle::read(is); // get the Vehicle info
            m_sidecar = ut.getYN(is); // get the Motorcycle info
            m_valid = true;
        } else {
            cout << "Motorcycle information entry" << endl;
            Vehicle::read(is);
            cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
            m_sidecar = ut.getYN(is);
            m_valid = true;
        }
        return is;
    }
    // overrides Vehicle write to display Vehicle info
    // and Motorcycle info
    std::ostream& Motorcycle::write(std::ostream& os) const {
        if (m_valid) {
            Vehicle::write(os);
            bool res = Vehicle::ReadWritable::isCsv();
            if (res)
                os << m_sidecar;
            else if (!res) {
                if (m_sidecar)
                    os << endl << "With Sidecar";
            }
        } else os << "Invalid Motorcycle Object" << endl;
        return os;
    }
}