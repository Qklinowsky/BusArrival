#include <cstdlib>
#include <iostream>
#include <list>
#include "BusStop.h"
#include "BusRoute.h"
#include "TimeTable.h"
#include "DataImporter.h"

using namespace std;

int main(int argc, char** argv) {
    DataImporter importer;
    list<BusRoute> wsyzsktieTrasy = importer.import("Lines");
    TimeTable timeTable = TimeTable(wsyzsktieTrasy);
    BusRoute linia12 = wsyzsktieTrasy.front();
    BusStop pierwszy = linia12.getBusStops().front();
    //wybor linii
    //wybor kierunku
    //wybor przystanku
    //wypisanei showTimeTable
    
    timeTable.showTimeTable(linia12, pierwszy);
    return 0;
}

