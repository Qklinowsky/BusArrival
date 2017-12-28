#define BOOST_ALL_DYN_LINK
#include <cstdlib>
#include <iostream>
#include <list>
#include "BusStop.h"
#include "BusRoute.h"
#include "TimeTable.h"
#include "DataImporter.h"
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

namespace logging = boost::log;
using namespace std;

BusRoute chooseRoute(TimeTable table);
BusStop chooseDirection(BusRoute route, TimeTable table);
BusStop chooseBusStop(BusRoute route);

void init()
{
    logging::core::get()->set_filter
    (
        logging::trivial::severity >= logging::trivial::debug
    );
}



int main(int argc, char** argv) {
    init();
    DataImporter importer;
    list<BusRoute> wsyzsktieTrasy = importer.import("Lines");

    TimeTable timeTable = TimeTable(wsyzsktieTrasy);
    BusRoute route = chooseRoute(timeTable);
    BusStop direction = chooseDirection(route, timeTable);
    BusRoute foundRoute = timeTable.findRoute(route.getName(), direction);
    BusStop chosenStop = chooseBusStop(foundRoute);
    timeTable.showTimeTable(foundRoute, chosenStop);
    return 0;
}

BusRoute chooseRoute(TimeTable table) {
    cout << "Wybierz linie z listy: \n";
    vector<BusRoute> availableRoutes = table.availableRoutes();
    int i = 0;
    for (auto route : availableRoutes) {
        cout << i << " - " << route.getName() << endl;
        i++;
    }
    int option;
    cin >> option;
    return availableRoutes.at(option);
}

BusStop chooseDirection(BusRoute route, TimeTable table) {

    cout << "Wybierz kierunek: \n";
    vector<BusStop> availableDestinations = table.availableDestinations(route.getName());
    int i = 0;
    for (auto destiantion : availableDestinations) {
        cout << i << " - " << destiantion.getName() << endl;
        i++;
    }
    int option;
    cin >> option;
    return availableDestinations.at(option);

}

BusStop chooseBusStop(BusRoute route) {
    cout << "Wybierz przystanek: \n";
    vector<BusStop> busStops = route.getBusStops();
    int i = 0;
    for (auto stop : busStops) {
        cout << i << " - " << stop.getName() << endl;
        i++;
    }
    int option;
    cin >> option;
    return busStops.at(option);
     



}
