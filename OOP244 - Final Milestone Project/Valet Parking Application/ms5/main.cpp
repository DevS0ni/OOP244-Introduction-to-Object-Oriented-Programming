#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctype.h>
#include <cstdlib>
#include "Parking.h"
#include "Utils.h"

using namespace std;
using namespace sdds;
void runParking(long numSpots = 10);
void Datafile(bool restore = false); // Change to true if you want to revert to original csv file

// accepts an argument for number of parking spots
// eg. './name_of_exe 50' will start the program with 50 spots *** between 10-100 ***
// if no argument is passed or it is not between 10 -100 then the deafault 10 spots is used
int main(int argc, char* argv[]) {
    if (argc > 1) {
        long numberOfSpots = strtol(argv[1], nullptr, 10);
        if (numberOfSpots > 10 && numberOfSpots <= 100)
            runParking(numberOfSpots);
        else
            runParking();
    } else runParking();
    
    Datafile();

    return 0;
}
void runParking(long numSpots) {
    Parking P("ParkingData.csv", numSpots);
    P.run();
}
void Datafile(bool restore) {
    char ch;
    ifstream file("ParkingData.csv");
    cout << endl << "Content of Data File - (ParkingData.csv)" << endl << endl;
    cout << "FORMAT:" << endl;
    cout << "type,spot,plate,make_model,carwash or sidecar 0-false, 1 - true" << endl;
    cout << "---------------------------------------------------------------" << endl;
    if (file.get(ch)) cout << char(ch);
    if (file.eof()) cout << setw(40) << "Empty File - Empty Lot" << endl;
    else {
        while (file.get(ch)) {
            cout << char(ch);
        }
    }
    cout << "---------------------------------------------------------------" << endl;
    if (restore) {
        cout << "Restore data file to original values? (y)es/(n)o: ";
        file.close();
        if (cin.get() == 'y') {
            char ch;
            file.open("ParkingData.csv.bak");
            ofstream fout("ParkingData.csv");
            while (file) {
                ch = file.get();
                if (file) fout.put(ch);
            }
            file.close();
            fout.close();
            cout << "Data file restored to orginal values." << endl;
        } else {
            cout << "Restoration aborted!" << endl;
        }
    }
}

