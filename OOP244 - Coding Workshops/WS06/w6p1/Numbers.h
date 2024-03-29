/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 Workshop 6 - part 1
-----------------------------------------------------------------------------
 */

#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_

#include <iostream>

namespace sdds {
   class Numbers {
      double* m_numbers{};
      char* m_filename{};
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty() const;
      void setEmpty();
      void deallocate();
      void setFilename(const char* filename);
   public:
      Numbers();
      Numbers(const char* filename);
      Numbers(const Numbers& N);
      Numbers& operator=(const Numbers& N);
      double average() const;
      double max() const;
      double min() const;
      ~Numbers();
      // my functions
      Numbers& sort(bool asc);
      Numbers operator-() const;
      Numbers operator+() const;
      int numberCount() const;
      bool load();
      void save();      
      Numbers& operator+=(double N);
      std::ostream& display(std::ostream& out) const;
   };
   std::ostream& operator<<(std::ostream& os, const Numbers& N);
   std::istream& operator>>(std::istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_

