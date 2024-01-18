/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 Workshop 9
-----------------------------------------------------------------------------
 */

// see implementation for comments

#ifndef SDDS_TEXT_H_
#define SDDS_TEXT_H_

#include <iostream>

namespace sdds {
    class Text {
        char* m_content{};
    protected:
        const char& operator[](int index) const;
    public:
        Text(const char* content = nullptr);
        Text(const Text& T);
        Text& operator=(const Text& T);
        virtual ~Text();
        std::istream& read(std::istream& is = std::cin);
        virtual std::ostream& write(std::ostream& os = std::cout) const;
    };
    std::istream& operator>>(std::istream& is, Text& T);
    std::ostream& operator<<(std::ostream& os, const Text& T);
    unsigned getFileLength(std::istream& is);
}


#endif // !SDDS_TEXT_H_
