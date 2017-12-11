#include <cstdlib>
#include <iostream>
#include <list>
#include "BusStop.h"
#include "BusRoute.h"
#include "TimeTable.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    BusStop pierwszy = BusStop("przystanek startowy");
    BusStop drugi = BusStop("przystanek drugi");
    BusStop trzeci = BusStop("przystanek koncowy");
    list<RouteSegment> route;
    route.push_back(RouteSegment(pierwszy, drugi, 2));
    route.push_back(RouteSegment(drugi, trzeci, 5));
    
    list<int> departureTimes;
    departureTimes.push_back(240);
    departureTimes.push_back(440);
    
    BusRoute linia1 = BusRoute("1", route, departureTimes);
    list<BusRoute> wsyzsktieTrasy;
    wsyzsktieTrasy.push_back(linia1);
    
    TimeTable timeTable = TimeTable(wsyzsktieTrasy);
    
    timeTable.showTimeTable(linia1, drugi);
 

    
            
    
    return 0;
}

