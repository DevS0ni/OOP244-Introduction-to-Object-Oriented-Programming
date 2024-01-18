/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 MileStone3
-----------------------------------------------------------------------------
 */

#include <iostream>
#include "Parking.h"

using namespace std;

namespace sdds {
    // Parking constructor - if path/filename is valid then allocate
    // memory and load the menus
    Parking::Parking(const char* path, int indent) : m_path(nullptr),
        m_menu("Parking Menu, select an action:", 0),
        m_Vmenu("Select type of the vehicle:", 1) {
        if (path && path[0] != '\0') {
            int length = ut.strlen(path);
            m_path = new char[length + 1];
            ut.strcpy(m_path, path, length);
        }
        if (loadData()) { // will eventually load data from file
            m_menu << "Park Vehicle" << "Return Vehicle" <<
                "List Parked Vehicles" << "Find Vehicle" <<
                "Close Parking (End of day)" << "Exit Program";
            m_Vmenu << "Car" << "Motorcycle" << "Cancel";
        } else cout << "Error in data file" << endl;
    }
    // parking program - nuts and boltd
    int Parking::run() {
        int choice, ret = 1;
        bool res = false;
        if (!isEmpty()) {
            ret = 0;
            do {
                status();
                choice = m_menu.run();
                if (choice == 1) park();
                else if (choice == 2) returnV();
                else if (choice == 3) list();
                else if (choice == 4) find();
                else if (choice == 5) res = close();
                else if (choice == 6) res = exitApp();
            } while (!res);
        }
        return ret;
    }
    Parking::~Parking() {
        saveData();
        delete[] m_path; // deallocate dynamic memory for path
    }
    bool Parking::isEmpty() const {
        return m_path == nullptr;
    }
    void Parking::status() const {
        cout << "****** Valet Parking ******" << endl;
    }
    // park a vehicle using the sub-menu for car or motorcycle
    void Parking::park() {
        int selection;
        selection = m_Vmenu.run();
        if (selection == 1) {
            cout << "---------------------------------" << endl;
            cout << "Parking Car" << endl;
            cout << "---------------------------------" << endl;
        } else if (selection == 2) {
            cout << "---------------------------------" << endl;
            cout << "Parking Motorcycle" << endl;
            cout << "---------------------------------" << endl;
        } else {
            cout << "---------------------------------" << endl;
            cout << "Cancelled parking" << endl;
            cout << "---------------------------------" << endl;
        } cout << endl;
    }
    // remove a veichle from the lot
    void Parking::returnV() {
        cout << "---------------------------------" << endl;
        cout << "Returning Vehicle" << endl;
        cout << "---------------------------------" << endl << endl;
    }
    // show vehicles in the lot
    void Parking::list() {
        cout << "---------------------------------" << endl;
        cout << "Listing Parked Vehicles" << endl;
        cout << "---------------------------------" << endl << endl;
    }
    // find a specific vehicle
    void Parking::find() {
        cout << "---------------------------------" << endl;
        cout << "Finding a Vehicle" << endl;
        cout << "---------------------------------" << endl << endl;
    }
    // close for the day and tow all vehicles from lot
    bool Parking::close() {
        bool res = false;
        cout << "This will close the parking; All the vehicles will be removed!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        if (ut.getYN()) {
            res = true;
            cout << "Ending application!" << endl;
        }
        return res;
    }
    // closes the app and saves data 
    bool Parking::exitApp() {
        bool res = false;
        cout << "This will terminate the application and save the data!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        if (ut.getYN()) {
            res = true;
            cout << "Exiting application!" << endl;
        }
        return res;
    }
    // loading and saving data to a file (eventually)
    bool Parking::loadData() {
        bool res = false;
        if (!isEmpty()) {
            cout << "---------------------------------" << endl;
            cout << "loading data from " << m_path << endl;
            cout << "---------------------------------" << endl << endl;
            res = true;
        }
        return res;
    }
    void Parking::saveData() {
        if (!isEmpty()) {
            cout << "---------------------------------" << endl;
            cout << "Saving data into " << m_path << endl;
            cout << "---------------------------------" << endl;
        }
    }
}