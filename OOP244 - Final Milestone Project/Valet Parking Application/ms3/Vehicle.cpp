/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 MileStone3
-----------------------------------------------------------------------------
 */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Vehicle.h"
#include "Utils.h"

using namespace std;

namespace sdds {
    void Vehicle::setEmpty() {
        delete[] m_makeModel;
        m_makeModel = nullptr;
        m_plate[0] = '\0';
        m_spot = 0;
    }
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
    Vehicle::Vehicle() :ReadWritable() {
        setEmpty();
    }
    Vehicle::Vehicle(const char* plate, const char* mkModel) 
        :ReadWritable()
    {
        if (plate && mkModel) {
            int plateLen = ut.strlen(plate);
            int mkModLen = ut.strlen(mkModel);
            if (plateLen > 0 && mkModLen > 1 && plateLen <= 8) {
                ut.strcpy(m_plate, plate, 8);
                setMakeModel(mkModel);
                m_spot = 0;
            } else setEmpty();
        } else setEmpty();
    }
    Vehicle::~Vehicle() {
        delete[] m_makeModel;
    }
    Vehicle::Vehicle(const Vehicle& V) {
        *this = V;
    }
    Vehicle& Vehicle::operator=(const Vehicle& V) {
        if (this != &V) {
            m_spot = V.m_spot;
            ut.strcpy(m_plate, V.m_plate, ut.strlen(V.m_plate));
            if (V.m_makeModel)
                setMakeModel(V.m_makeModel);
            else setEmpty();
        }
        return *this;
    }
    void Vehicle::setMakeModel(const char* mkModel) {
        int len = ut.strlen(mkModel);
        if (mkModel && len > 1 && len <= 60) {
            delete[] m_makeModel;
            m_makeModel = new char[len + 1];
            ut.strcpy(m_makeModel, mkModel, ut.strlen(mkModel));
        } else setEmpty();
    }
    void Vehicle::setParkingSpot(int spot) {
        if (spot >= 0)
            m_spot = spot;
        else setEmpty();
    }

    bool Vehicle::operator==(const char* plate) const {
        int cmp = ut.stricmp(m_plate, plate);
        return cmp == 0;
    }
    bool Vehicle::operator==(const Vehicle& V) const {
        int cmp = ut.stricmp(m_plate, V.m_plate);
        return cmp == 0;
    }
    std::istream& Vehicle::read(std::istream& is) {
        char plate[9]{};
        char mkModel[61]{};
        if (ReadWritable::isCsv()) { // check if scv or not
            is >> m_spot;
            is.ignore(); // ,
            // use utils getDyn Str
            ut.getStr(plate, true, is);
            ut.strcpy(m_plate, plate, ut.strlen(plate));
            ut.getStr(mkModel, false, is);
            setMakeModel(mkModel);
        } else {
            bool ok = false;
            cout << "Enter Licence Plate Number: ";
            do {
                if (ut.getStr(plate, true, is) >= 8) {
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
        return is;
    }
    std::ostream& Vehicle::write(std::ostream& os) const {
        if (isEmpty())
            os << "Invalid Vehicle Object" << endl;
        else {
            writeType(os);
            if (ReadWritable::isCsv()) {
                os << getParkingSpot() << "," << getLicencePlate()
                    << "," << getMakeModel() << ",";
            } else {
                os << "Parking Spot Number: ";
                if (getParkingSpot() == 0) os << "N/A" << endl;
                else os << m_spot << endl;
                os << "Licence Plate: " << getLicencePlate() << endl;
                os << "Make and Model: " << getMakeModel() << endl;
            }
        }
        return os;
    }
}