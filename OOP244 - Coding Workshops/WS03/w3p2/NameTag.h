/*
-----------------------------------------------------------------------------
 Author      : Dev Soni - dasoni4@myseneca.ca
 Student #   : 130759210
 Section     : NAA
 Workshop 3 - part 2
-----------------------------------------------------------------------------
 */

#ifndef SDDS_NAMETAG_H_
#define SDDS_NAMETAG_H_

namespace sdds {

	class NameTag {
		char m_name[51];		
	public:
		void set(const char* name);
		void set(const NameTag& nt);		
		void display(const NameTag* nt, int numTags) const;
	};
}
#endif