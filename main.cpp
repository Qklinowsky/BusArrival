#include <cstdlib>
#include <iostream>
#include <list>
#include "BusStop.h"
#include "BusRoute.h"
#include "TimeTable.h"
#include "DataImporter.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    DataImporter importer;
    BusRoute linia12 = importer.import("Linia12.txt");
   
    
    list<BusRoute> wsyzsktieTrasy;
    wsyzsktieTrasy.push_back(linia12);
    
    TimeTable timeTable = TimeTable(wsyzsktieTrasy);
    
    BusStop pierwszy = linia12.getBusStops().front();
    
    timeTable.showTimeTable(linia12, pierwszy);
 

    
            
    
    return 0;
}

