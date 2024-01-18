/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 Workshop 4 - part 2
-----------------------------------------------------------------------------
 */

#ifndef SDDS_TOURBUS_H_
#define SDDS_TOURBUS_H_

#include "TourTicket.h"

namespace sdds {
	// TourBus class
	class TourBus {
		TourTicket* m_passenger;
		int m_numTickets;
		int m_numCheckedIn;		
		bool isEmpty()const;
		bool fullBus()const;
		void init();
	public:
		TourBus();
		TourBus(int num);
		~TourBus();
		bool validTour()const;
		TourBus& board();	
		void startTheTour()const;
	};
}

#endif