/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 MileStone2
-----------------------------------------------------------------------------
 */

#ifndef SDDS_PARKING_H_
#define SDDS_PARKING_H_

#include "Menu.h"

namespace sdds {
    class Parking {
        char* m_path;
        // parking class -- HAS Menu(s) - not IS a Menu
        Menu m_menu;
        Menu m_Vmenu; // sub - Menu for type of Vehicle
        bool isEmpty();
        void status();
        void park();
        void returnV();
        void list();
        void find();
        bool close();
        bool exitApp();
        bool loadData();
        void saveData();
    public:
        Parking(const char* path, int indent = 0);
        Parking(const Parking& P) = delete;
        Parking& operator=(const Parking& P) = delete;
        int run();
        // making distructor virtual ensures that if Parking inherited a base class 
        // and our main() was using pointers or references to a Parking obj, 
        // the base class destructors would still get called and we won't have 
        // memory leaks
        virtual ~Parking();
        
    };
}

#endif // !SDDS_PARKING_H_