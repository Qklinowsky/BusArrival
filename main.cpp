#include <cstdlib>
#include <iostream>
#include <list>
#include "BusStop.h"
#include "BusRoute.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "Witaj swiecie";
    BusStop pierwszyPrzystanek = BusStop("przystanek startowy");
    BusStop ostatniPrzystanek = BusStop("przystanek koncowy");
    cout << "Pierwszy przystanek to " << pierwszyPrzystanek.getName();
    list<BusStop> listOfBusStops;
    listOfBusStops.push_back(pierwszyPrzystanek);
    listOfBusStops.push_back(ostatniPrzystanek);

    BusRoute rw1 = BusRoute(listOfBusStops);
    
            
    
    list<BusStop>::iterator it = listOfBusStops.begin();
    while (it != listOfBusStops.end()) {
        std::cout << (it->getName()) << "  ";
        it++;
    }
    return 0;
}

