/*
*****************************************************************************
                              Label.cpp
Full Name  : Dev Soni
Student ID#: 130759210
Email      : dasoni4@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Label.h"
#include <cstring>

namespace sdds {
    void Label::setToDefault() {
        m_frame = nullptr;
        m_content = nullptr;
    }

    void Label::setFrame(const char* frameArg) {
        delete[] m_frame;
        m_frame = new char[strlen(frameArg) + 1];
        strcpy(m_frame, frameArg);
    }

    void Label::setContent(const char* contentArg) {
        delete[] m_content;
        m_content = new char[strlen(contentArg) + 1];
        strcpy(m_content, contentArg);
    }

    Label::Label() {
        setToDefault();
        setFrame("+-+|+-+|");
    }

    Label::Label(const char* frameArg) {
        setToDefault();
        setFrame(frameArg);
    }

    Label::Label(const char* frameArg, const char* contentArg) {
        setToDefault();
        setFrame(frameArg);
        setContent(contentArg);
    }

    Label::~Label() {
        delete[] m_frame;
        delete[] m_content;
    }

    void Label::readLabel() {
        char temp[71];
        std::cin.getline(temp, 71);
        setContent(temp);
    }

    std::ostream& Label::printLabel() const {

        if (m_frame != nullptr && m_content != nullptr) {
            int len = strlen(m_content);
            int frameLen = strlen(m_frame);
            int width = len + 2;
            if (frameLen > width)
                width = frameLen;

            std::cout << m_frame[0];
            for (int i = 0; i < width; i++)
                std::cout << m_frame[1];
            std::cout << m_frame[2] << std::endl;

            std::cout << m_frame[7];
            for (int i = 0; i < width; i++)
                std::cout << ' ';
            std::cout << m_frame[3] << std::endl;

            std::cout << m_frame[7] << ' ';
            std::cout << m_content;
            for (int i = len; i < width - 1; i++)
                std::cout << ' ';
            std::cout << m_frame[3] << std::endl;

            std::cout << m_frame[7];
            for (int i = 0; i < width; i++)
                std::cout << ' ';
            std::cout << m_frame[3] << std::endl;

            std::cout << m_frame[6];
            for (int i = 0; i < width; i++)
                std::cout << m_frame[5];
            std::cout << m_frame[4];
        }
        return std::cout;
    }
}