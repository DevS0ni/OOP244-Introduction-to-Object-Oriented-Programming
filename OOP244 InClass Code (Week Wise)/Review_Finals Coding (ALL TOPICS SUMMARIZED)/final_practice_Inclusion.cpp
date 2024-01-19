#include <iostream>
using namespace std;

// Balloon Class

class Balloon{

	int air;

  public:

	Balloon(int p_air=5) {

	  air = p_air;

	  std::cout<< "BL" << std::endl;

	}

	Balloon& operator++() {

	  air++;

	  std::cout<< "BL++ " << air << std::endl;

	  return *this;

	}

	virtual void propel(int distance) {

	  int air_cost = distance * 2;

	  if(air_cost > air) {

		std::cout<< "NEA " << air_cost << std::endl;

	  }

	  air -= air_cost;

	}

	virtual ~Balloon() { std::cout << "DB " << air << std::endl; }

};

// HotAirBalloon Class

class HotAirBalloon : public Balloon{

  int heat;

  public:

	HotAirBalloon(int p_heat = 5, int p_air = 60) : Balloon (p_air) {

	  heat = p_heat;

	  std::cout << "HA" << std::endl;
	}

	HotAirBalloon& operator++() {

	  Balloon::operator++();

	  heat++;

	  std::cout << "HA++ " << heat << std::endl;
	}

	void propel(int distance) {

	  if(heat > 80) {

		std::cout << "HOT" << std::endl;

		Balloon::propel(distance - 2);
	  }

	  else{

		std::cout << "COLD" << std::endl;

		Balloon::propel(distance + 2);
	  }

	  heat -= 10;

	}

	~HotAirBalloon() { std::cout << "DHA " << heat << std::endl; }

};



// Main Function

int main() {
	Balloon b;
	Balloon* bb[3];

	bb[0] = new Balloon();

	bb[1] = new HotAirBalloon(80);

	bb[2] = new HotAirBalloon(85, 100);

}

/*

BL
BL
HA
BL
HA

*/