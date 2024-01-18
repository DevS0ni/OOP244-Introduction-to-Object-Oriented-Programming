#ifndef LABEL_H_
#define LABEL_H_

/*
*****************************************************************************
                              Label.h
Full Name  : Dev Soni
Student ID#: 130759210
Email      : dasoni4@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>

namespace sdds {
    class Label {
        char* m_frame;
        char* m_content;
        void setToDefault();
        void setFrame(const char* frameArg);
        void setContent(const char* contentArg);
    public:
        Label();
        Label(const char* frameArg);
        Label(const char* frameArg, const char* contentArg);
        ~Label();
        void readLabel();
        std::ostream& printLabel() const;
    };
}

#endif /* LABEL_H_ */