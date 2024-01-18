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
#include "Vehicle.h"
#include "Utils.h"

using namespace std;

namespace sdds {
    // Set the vehicle to a safe empty state
    void Vehicle::setEmpty() {
        delete[] m_makeModel;
        m_makeModel = nullptr;
        m_plate[0] = '\0';
        m_spot = 0;
    }
    // queries
    bool Vehicle::isEmpty() const {
        return m_makeModel == nullptr;
    }
    const char* Vehicle::getLicencePlate() const {
        return m_plate;
    }
    const char* Vehicle::getMakeModel() const {
        return m_makeModel;
    }
    int Vehicle::getParkingSpot() const {
        return m_spot;
    }
    // constructors & destructor
    Vehicle::Vehicle() :ReadWritable() {}
    Vehicle::Vehicle(const char* plate, const char* mkModel)
        :ReadWritable() {
        if (plate && mkModel) {
            int plateLen = ut.strlen(plate);
            int mkModLen = ut.strlen(mkModel);
            if (plateLen > 0 && mkModLen > 1 && plateLen <= 8) {
                ut.strcpy(m_plate, plate);
                setMakeModel(mkModel);
                m_spot = 0;
            } else setEmpty();
        } else setEmpty();
    }
    Vehicle::~Vehicle() {
        delete[] m_makeModel;
    }
    // copy constructor/assignment - ensures against self copy and
    //  that we keep track of the csv boolean
    Vehicle& Vehicle::operator=(const Vehicle& V) {
        if (this != &V) {
            m_spot = V.m_spot;
            Vehicle::setCsv(V.isCsv()); // csv is remembered
            ut.strcpy(m_plate, V.m_plate, ut.strlen(V.m_plate));
            if (V.m_makeModel)
                setMakeModel(V.m_makeModel);
            else setEmpty();
        }
        return *this;
    }
    Vehicle::Vehicle(const Vehicle& V) {
        *this = V;
    }
    // sets the dynamic make ond model
    void Vehicle::setMakeModel(const char* mkModel) {
        int len = ut.strlen(mkModel);
        if (mkModel && len > 1 && len <= 60) {
            delete[] m_makeModel;
            m_makeModel = nullptr;
            m_makeModel = ut.alcpy(mkModel);
        } else setEmpty();
    }
    // sets a vaild parking spot
    void Vehicle::setParkingSpot(int spot) {
        if (spot >= 0)
            m_spot = spot;
        else setEmpty();
    }
    // == overloads to compare plates (case insensitive)
    bool Vehicle::operator==(const char* plate) const {
        int cmp = ut.stricmp(m_plate, plate);
        return cmp == 0;
    }
    bool Vehicle::operator==(const Vehicle& V) const {
        int cmp = ut.stricmp(m_plate, V.m_plate);
        return cmp == 0;
    }
    // read implimentation of base pure virtual
    // gets information about the vehicle
    std::istream& Vehicle::read(std::istream& is) {
        char* plate = new char[128] {'\0'};
        char* mkModel = new char[128] {'\0'};
        if (ReadWritable::isCsv()) {
            is >> m_spot;
            if (m_spot > 0) {
                is.ignore(); // ,
                ut.getStr(plate, true, is);
                ut.strcpy(m_plate, plate, ut.strlen(plate));
                ut.getStr(mkModel, false, is);
                setMakeModel(mkModel);
            } else setEmpty();
        } else {
            bool ok = false;
            cout << "Enter Licence Plate Number: ";
            do {
                if (ut.getStr(plate, true, is) > 8) {
                    cout << "Invalid Licence Plate, try again: ";
                } else {
                    ok = true;
                    ut.strcpy(m_plate, plate);
                }
            } while (!ok);
            ok = false;
            cout << "Enter Make and Model: ";
            do {
                int len = ut.getStr(mkModel, false, is);
                if (len > 60 || len < 2) {
                    cout << "Invalid Make and model, try again: ";
                } else {
                    ok = true;
                    setMakeModel(mkModel);
                }
            } while (!ok);
            m_spot = 0;
        }
        delete[] plate;
        delete[] mkModel;
        return is;
    }
    // write implimentation of base pure virtual
    // displays information about the Vehicle
    std::ostream& Vehicle::write(std::ostream& os) const {
        if (isEmpty())
            os << "Invalid Vehicle Object" << endl;
        else {
            writeType(os);
            if (ReadWritable::isCsv()) { // check if csv
                os << getParkingSpot() << "," << getLicencePlate()
                    << "," << getMakeModel() << ",";
            } else {
                os << "Parking Spot Number: ";
                if (getParkingSpot() == 0) os << "N/A" << endl;
                else os << m_spot << endl;
                os << "Licence Plate: " << getLicencePlate() << endl;
                os << "Make and Model: " << getMakeModel();
            }
        }
        return os;
    }
}