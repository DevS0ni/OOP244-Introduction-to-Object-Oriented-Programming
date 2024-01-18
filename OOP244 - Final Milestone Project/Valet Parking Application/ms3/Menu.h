/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 MileStone3
-----------------------------------------------------------------------------
 */

#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_

#include <iostream>
#include "Utils.h"

namespace sdds {
    const int MAX_NO_OF_ITEMS = 6;

    // MenuItem private class and implementation
    // - owned by Menu - reason to use friend
    class MenuItem {
        char m_item[51];
        // deleted copy and assignment opertors
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;
        // display
        std::ostream& display(std::ostream& ostr = std::cout) const {
            if (m_item) ostr << m_item << std::endl;
            return ostr;
        }
        // constructor
        MenuItem(const char* content = nullptr) : m_item{ 0 } {
            if (content) ut.strcpy(m_item, content, 50);
            else m_item[0] = 0;
        }
        friend class Menu; // Menu owns MenuItem
    };
    // Menu class - owns MenuItem
    class Menu {
        char m_title[51];
        int m_indent;
        int m_numItems;
        bool m_valid;
        MenuItem m_items[MAX_NO_OF_ITEMS];
        bool isEmpty() const;
        bool isFull() const;
        bool isValid() const;
        void indent(int num) const;
        void addItem(const char* item);
    public:
        void clear();
        // constructor, copy, and assignment
        Menu(const char* title, int indent = 0);
        // deleted copy constructor and assignment operator
        Menu(const Menu& src) = delete;
        Menu& operator=(const Menu& src) = delete;
        // set title
        Menu& operator=(const char* newTitle);
        // add list items
        Menu& operator<<(const char* item);
        void add(const char* item);
        // check validity
        operator bool() const;
        // calls run
        operator int() const;
        // calls display
        int run() const;
        // disply
        std::ostream& display(std::ostream& ostr = std::cout) const;
    };
    // ostream helper
    std::ostream& operator<<(Menu& menu, std::ostream& ostr);
}

#endif // !SDDS_MENU_H_
