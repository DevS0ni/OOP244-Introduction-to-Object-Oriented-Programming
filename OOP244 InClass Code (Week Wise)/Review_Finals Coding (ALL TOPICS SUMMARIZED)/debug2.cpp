class Box {

	double weight;

public:
	//assume prefix is implemented

	Box& operator++(int) {

		Box store = *this;
		++(*this);
		return store;

	}

};


ERROR 1:    Line number : _________
Problem : ____________________________________________________________________________________________________________________________________________________________

Fix :
