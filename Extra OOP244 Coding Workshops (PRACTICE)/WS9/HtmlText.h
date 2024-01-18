/*************************************************************
// File    HtmlText.h
// Version 1.0
// Author  dasoni4@myseneca.ca
// Description:
// HtmlText header File
// --------------------------------------
// Name            Date            Reason
// ----            ----            ------
//                                 Initial Version 1.0
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the
// code that my professor provided to complete my project
// milestones.
// -----------------------------------------------------------
*************************************************************/

#ifndef SDDS_HTMLTEXT_H_
#define SDDS_HTMLTEXT_H_

#include <iostream>
#include "Text.h"

// see implementation for comments
namespace sdds {
    class HtmlText : public Text{
        char* m_title{};
    public:
         HtmlText(const char* filename = nullptr, const char* title = nullptr);
        HtmlText& operator=(const HtmlText& H);
        HtmlText(const HtmlText& html);
        virtual ~HtmlText();
        std::ostream& write(std::ostream& os = std::cout) const;
    };
}

#endif // !SDDS_HTMLTEXT_H_