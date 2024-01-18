/*
*****************************************************************************
                              Food.h
Full Name  : Dev Soni
Student ID#: 130759210
Email      : dasoni4@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_FOOD_H
#define SDDS_FOOD_H

const int MAX_NAME_LENGTH = 30;

namespace sdds {
        class Food {
            char m_name[MAX_NAME_LENGTH + 1];
            int m_calories;
            int m_when;

        public:
            void setEmpty();
            void set(const char* name, int calories, int when);
            bool isValid() const;
            void display() const;
            int calories() const;
        };
}

#endif // !SDDS_FOOD_H
