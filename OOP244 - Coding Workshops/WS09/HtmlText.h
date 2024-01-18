/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 Workshop 9
-----------------------------------------------------------------------------
 */

#ifndef SDDS_HTMLTEXT_H_
#define SDDS_HTMLTEXT_H_

#include <iostream>
#include "Text.h"

// see implementation for comments
namespace sdds {
    class HtmlText : public Text{
        char* m_title{};
    public:
        HtmlText(const char* title = nullptr);
        HtmlText& operator=(const HtmlText& H);
        HtmlText(const HtmlText& html);
        virtual ~HtmlText();
        std::ostream& write(std::ostream& os = std::cout) const;
    };
}

#endif // !SDDS_HTMLTEXT_H_
