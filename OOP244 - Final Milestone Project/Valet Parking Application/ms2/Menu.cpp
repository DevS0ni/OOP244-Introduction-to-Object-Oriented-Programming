/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 MileStone2
-----------------------------------------------------------------------------
 */

#include <iostream>
#include "Menu.h"
#include "Utils.h"

using namespace std;

namespace sdds {
    // Menu constructor
    Menu::Menu(const char* title, int indent) : m_title{ 0 }, m_indent(0), 
        m_numItems(0), m_valid(false) {
        if (title) {
            m_valid = true;
            m_indent = indent;
            // can use Utils - ut because of extern
            ut.strcpy(m_title, title, 50);
        } else m_valid = false;
    }
    // private queries and indent helper
    bool Menu::isEmpty() const {
        return m_numItems == 0;
    }
    bool Menu::isFull() const {
        return m_numItems == MAX_NO_OF_ITEMS;
    }
    bool Menu::isValid() const {
        return m_valid;
    }
    void Menu::indent(int num) const {
        for (int i = 0; i < num; i++) cout << "    ";
    }
    // set menu empty
    void Menu::clear() {
        m_title[0] = 0;
        m_indent = 0;
        m_numItems = 0;
    }
    // bool and int overloads
    Menu::operator bool() const {
        return isValid();
    }
    Menu::operator int() const {
        return run();
    }
    // set the menu title with = overload
    Menu& Menu::operator=(const char* newTitle) {
        if (newTitle)
            ut.strcpy(m_title, newTitle, 50);
        else m_valid = false;
        return *this;
    }
    // private logic for add() and << - to add a list item
    void Menu::addItem(const char* item) {
        if (item && !isFull() && isValid()) {
            ut.strcpy(m_items[m_numItems].m_item, item, 50);
            m_numItems++;
        } else m_valid = false;
    }
    // add items to the menu using << overload and add()
    Menu& Menu::operator<<(const char* item) {
        addItem(item);
        return *this;
    }
    void Menu::add(const char* item) {
        addItem(item);
    }
    // display menu and get selection from user
    int Menu::run() const {
        int num = 0;
        display();
        if (!isEmpty() && isValid())
            num = ut.getInt(1, m_numItems);
        return num;
    }
    // display returning ostream reference
    std::ostream& Menu::display(std::ostream& ostr) const {
        if (!isValid())
            ostr << "Invalid Menu!" << endl;
        else if (isEmpty()) {
            ostr << m_title << endl;
            ostr << "No Items to display!" << endl;
        } else {
            indent(m_indent);
            ostr << m_title << endl;
            for (int i = 0; i < m_numItems; i++) {
                indent(m_indent);
                ostr << i + 1 << "- ";
                m_items[i].display(ostr);
            }
            indent(m_indent);
            ostr << "> ";
        }
        return ostr;
    }
    // output helper
    std::ostream& operator<<(Menu& menu, std::ostream& ostr) {
        menu.display(ostr);
        return ostr;
    }
}