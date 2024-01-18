/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 MileStone5
-----------------------------------------------------------------------------
 */

#ifdef _WIN32
#include <Windows.h>
#endif

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Parking.h"
#include "Utils.h"
#include "Car.h"
#include "Motorcycle.h"

void clrscr() {
#ifdef _WIN32
    COORD tl = { 0,0 };
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &s);
    DWORD written, cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console, ' ', cells, tl, &written);
    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
    SetConsoleCursorPosition(console, tl);
#else
    system("clear");
#endif
}

using namespace std;

namespace sdds {
    // Parking constructor - if path/filename is valid then allocate
    // memory and load the menus
    Parking::Parking(const char* path, int numSpots) : m_path(nullptr),
        m_menu("Parking Menu, select an action:", 0),
        m_Vmenu("Select type of the vehicle:", 1) {
        if (path && path[0] != '\0' && numSpots <= m_numSpots && numSpots > 0) {
            m_numSpots = numSpots;
            m_path = ut.alcpy(path);
            for (int i = 0; i < MAX_PARKING_SPOTS; i++)
                m_vehicles[i] = nullptr;
        }
        if (loadData()) { // loads file data and populates menu's
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
    bool Parking::isEmpty() const {
        return m_path == nullptr;
    }
    void Parking::status() const {
        clrscr();
        cout << "********* Valet Parking **********" << endl;
        cout << "*****  Available spots: ";
        cout.setf(ios::left);
        cout << setw(5) << m_numSpots - m_numParked << "*****" << endl;
        cout.unsetf(ios::left);
    }
    // created to eliminate duplicate logic from park()
    void Parking::parkVehicle(Vehicle* V, int loc) {
        V->setCsv(false);
        cout << endl;
        cin >> *V;
        V->setParkingSpot(loc + 1);
        cout << endl << "Parking Ticket:" << endl;
        cout << "---------------" << endl;
        cout << *V;
        cout << endl << endl;
        m_numParked++;
    }
    // park a vehicle using the sub-menu for car or motorcycle
    void Parking::park() {
        int selection, spotFound = -1;
        for (int i = 0; i < m_numSpots && spotFound == -1; i++)
            if (!m_vehicles[i])
                spotFound = i;
        if (spotFound >= 0) {
            selection = m_Vmenu.run();
            if (selection == 1) {
                m_vehicles[spotFound] = new Car;
                parkVehicle(m_vehicles[spotFound], spotFound);
            } else if (selection == 2) {
                m_vehicles[spotFound] = new Motorcycle;
                parkVehicle(m_vehicles[spotFound], spotFound);
            }
        } else {
            cout << "Parking lot is full!\nTry Returning a Vehicle " << endl << endl;
        }
        pause();
    }
    // based on a licence plate - find a parked vehicle
    // return -1 if not found and the index if found
    // display if found using the correct heading
    int Parking::findVehicle(const char* heading) {
        const char* plate{};
        int loc = -1;
        plate = ut.getDynCstr("Enter Licence Plate Number: ");
        int len = ut.strlen(plate);
        while (len < 1 || len > 8) {
            plate = ut.getDynCstr("Invalid Licence Plate, try again: ");
            len = ut.strlen(plate);
        }
        for (int i = 0; i < m_numSpots && loc == -1; i++)
            if (m_vehicles[i])
                if (*m_vehicles[i] == plate)
                    loc = i;
        if (loc == -1) {
            cout << endl << "Licence plate \'";
            ut.toUpper(plate, cout);
            cout << "\' Not found!" << endl << endl;
        } else {
            cout << endl << heading << endl;
            cout << "---------------" << endl;
            m_vehicles[loc]->setCsv(false);
            cout << *m_vehicles[loc];
            cout << endl << endl;
        }
        delete[] plate;
        return loc;
    }
    void Parking::pause() {
        cout << "Press <ENTER> to continue...\nThis will clear the screen and return to the menu!";
        cin.ignore(1000, '\n');
    }
    // remove a veichle from the lot
    void Parking::returnV() {
        cout << "Return Vehicle:" << endl;
        cout << "---------------" << endl;
        int index = findVehicle("Returning:");
        if (index != -1) {
            delete m_vehicles[index];
            m_vehicles[index] = nullptr;
            m_numParked--;
        }
        pause();
    }
    // find a specific vehicle
    void Parking::find() {
        cout << "Vehicle Search" << endl;
        findVehicle("Vehicle found: ");
        pause();
    }
    // show vehicles in the lot
    void Parking::list() {
        if (m_numParked) {
            cout << endl << "-------------------------------" << endl;
            cout << "*** List of parked vehicles ***" << endl;
            cout << "-------------------------------" << endl;
            for (int i = 0; i < m_numSpots; i++)
                if (m_vehicles[i]) {
                    m_vehicles[i]->setCsv(false);
                    //m_vehicles[i]->write(cout) << endl;
                    cout << *m_vehicles[i] << endl;;
                    cout << "-------------------------------" << endl;
                }
            cout << "********  End of List  ********" << endl;
            cout << "-------------------------------" << endl;
        } else {
            cout << endl << "-------------------------------" << endl;
            cout << "No vehicles are parked!" << endl << endl;
            cout << "-------------------------------" << endl;
        }
        cout << endl;
        pause();
    }
    // close for the day and tow all vehicles from lot
    bool Parking::close() {
        bool res = false;
        if (m_numParked == 0) {
            cout << "Closing Parking" << endl;
            res = true;
        } else {
            cout << "This will Remove and tow all remaining vehicles from the parking!"
                << endl;
            cout << "Are you sure? (Y)es/(N)o: ";
            if (ut.getYN(cin)) {
                res = true;
                cout << "Closing Parking" << endl;
                for (int i = 0; i < m_numSpots; i++)
                    if (m_vehicles[i]) {
                        cout << endl << "Towing request" <<
                            endl << "*********************" << endl;
                        m_vehicles[i]->setCsv(false);
                        cout << *m_vehicles[i] << endl;
                        delete m_vehicles[i];
                        m_vehicles[i] = nullptr;
                    }
            } else {
                cout << "\nReturning to menu..." << endl;
                cout << "--------------------" << endl;
                pause();
            }
            saveData();
        }
        return res;
    }
    // closes the app and saves data 
    bool Parking::exitApp() {
        bool res = false;
        cout << "This will terminate the program!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        if (ut.getYN(cin)) {
            res = true;
            cout << "\nExiting program" << endl;
            cout << "And Saving Data" << endl;
            cout << "---------------" << endl;
            saveData();
        } else {
            cout << "\nReturning to menu..." << endl;
            cout << "--------------------" << endl;
            pause();
        }
        return res;
    }
    // make sure there is no memory leaks
    Parking::~Parking() {
        // delete the filename/path
        delete[] m_path;
        // delete all the cars from Vehicle pointer array
        for (int i = 0; i < m_numSpots; i++)
            delete m_vehicles[i];
    }
    // loading data from the file
    bool Parking::loadData() {
        bool res = true;
        bool ok = true;
        char ch;
        Vehicle* V{};
        ifstream fin(m_path);
        while (ok && m_numParked < m_numSpots) {
            fin.get(ch);
            if (!fin.eof()) { // dont do enything file is empty or at EOF
                V = nullptr;
                if (ch == 'C' || ch == 'c') V = new Car;
                else if (ch == 'M' || ch == 'm') V = new Motorcycle;
                else res = false; // only happens if trying to read an invalid file
                fin.ignore(); // ignore , after type of V
                if (res) {
                    V->setCsv(true);
                    fin >> *V;
                    m_vehicles[V->getParkingSpot() - 1] = V;
                    m_numParked++;
                }
            } else ok = false;
        }
        fin.close();
        return res;
    }
    // saving the data back to the file
    void Parking::saveData() {
        ofstream fout(m_path);
        if (fout) {
            for (int i = 0; i < m_numSpots; i++)
                if (m_vehicles[i]) {
                    m_vehicles[i]->setCsv(true);
                    fout << *m_vehicles[i] << endl;
                }
            fout.close();
        } else cout << "Couldn't open file " << m_path << endl;
    }
}