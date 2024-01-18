/*
*****************************************************************************
                              LabelMaker.h
Full Name  : Dev Soni
Student ID#: 130759210
Email      : dasoni4@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/ 
#ifndef LABELMAKER_H_
#define LABELMAKER_H_

#include "Label.h"

namespace sdds {
    class LabelMaker {
        int m_noOfLabels;
        Label* m_labels;
    public:
        LabelMaker();
        LabelMaker(int noOfLabels);
        ~LabelMaker();
        void readLabels();
        void printLabels() const;
    };
}

#endif /* LABELMAKER_H_ */