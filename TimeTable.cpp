#include <stdexcept>
#include <algorithm>
#include <string>
#include "TimeTable.h"
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::gregorian;

TimeTable::TimeTable(list<BusRoute> routes) : routes(routes) {
}

TimeTable::~TimeTable() {
}

void TimeTable::showTimeTable(BusRoute& route, BusStop& stop) {
    time_facet *facet = new time_facet("%H:%M");
    cout.imbue(locale(cout.getloc(), facet));

    string routeName = route.getName();
    std::cout << "Rozkład jazdy dla lini: " << routeName << endl;
    std::cout << "Dla przystanku: " << stop.getName() << endl;
    std::cout << "W kierunku: " << route.getDirection().getName() << endl;
    std::cout << "Godziny odjazdu: " << endl;
    list<ptime> busStopDepartureTimes = route.getDepartureTime(stop);
    for (ptime departureTime : busStopDepartureTimes) {
        std::cout << departureTime << endl;
    }
    route.printRoute(stop);
}

vector<BusRoute> TimeTable::availableRoutes() {
    vector<BusRoute> busRoutes;
    for (auto route : routes) {
        if(!contains(busRoutes, route)){
            busRoutes.push_back(route);
        }
        
    }
    std::sort (busRoutes.begin(), busRoutes.end()); 

    return busRoutes;
}

vector<BusStop> TimeTable::availableDestinations(string lineName) {
    vector<BusStop> destinations;
    for (auto route : routes) {
        if (route.getName() == lineName) {
            destinations.push_back(route.getDirection());
        }

    }
    return destinations;

}

vector<BusStop> TimeTable::availableBusStops(string lineName, BusStop destination) {
    for (auto route : routes) {
         if ((route.getName() == lineName) && (route.getDirection() == destination)) {
            return route.getBusStops();
        }
    }
}
bool TimeTable::contains(vector<BusRoute> routes, BusRoute route) {
    vector<BusRoute>::iterator it = routes.begin();
    while (it != routes.end()) {
        if (it->getName() == route.getName()) {
            return true;
        }
        it++;
    }
    return false;
}

BusRoute TimeTable::findRoute(string name, BusStop direction) {
    for (auto route : routes) {
        if(route.getName() == name && route.getDirection() == direction){
            return route;
        }
    }
    throw std::invalid_argument("Nie znaleziono pasującej trasy.");

}

 


