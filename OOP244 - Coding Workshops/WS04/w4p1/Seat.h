/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 Workshop 4 - part 1
-----------------------------------------------------------------------------
 */

#ifndef SDDS_SEAT_H_
#define SDDS_SEAT_H_

#include <iostream>

namespace sdds {

	class Seat {
		char* m_name = nullptr;
		int m_row = 0;
		char m_seat = '\0';

		bool validate(int row, char seat)const;
		Seat& alAndCp(const char* str);
	public:
		Seat& reset();
		bool isEmpty()const;
		bool assigned()const;
		Seat();
		Seat(const char* name);
		Seat(const char* name, int row, char seat);
		~Seat();
		Seat& set(int row, char seat);
		int row()const;
		char letter()const;
		const char* passenger()const;
		std::ostream& display(std::ostream& coutRef = std::cout)const;
		std::istream& read(std::istream& cinRef = std::cin);
	};
}

#endif // !SDDS_SEAT_H_