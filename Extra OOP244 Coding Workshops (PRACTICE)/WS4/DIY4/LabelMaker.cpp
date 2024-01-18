/*
*****************************************************************************
                              LabelMaker.cpp
Full Name  : Dev Soni
Student ID#: 130759210
Email      : dasoni4@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LabelMaker.h"

namespace sdds {
    LabelMaker::LabelMaker() : m_noOfLabels(0), m_labels(nullptr) {}

    LabelMaker::LabelMaker(int noOfLabels) : m_noOfLabels(noOfLabels), m_labels(nullptr) {
        if (m_noOfLabels > 0) {
            m_labels = new Label[m_noOfLabels];
        }
    }

    LabelMaker::~LabelMaker() {
        delete[] m_labels;
    }

    void LabelMaker::readLabels() {
        if (m_labels) {
            std::cout << "Enter " << m_noOfLabels << " labels:\n";
            for (int i = 0; i < m_noOfLabels; i++) {
                std::cout << "Enter label number " << i + 1 << std::endl << "> ";
                m_labels[i].readLabel();
            }
        }
    }

    void LabelMaker::printLabels() const {
        if (m_labels) {
            for (int i = 0; i < m_noOfLabels; i++) {
                //std::cout << std::endl;
                m_labels[i].printLabel();
                std::cout << std::endl;
            }
        }
    }
}