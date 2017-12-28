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

vector<BusRoute> TimeTable::allAvailableRoutes() {
    vector<BusRoute> busRoutes;
    for (auto route : routes) {
        if (!contains(busRoutes, route)) {
            busRoutes.push_back(route);
        }

    }
    std::sort(busRoutes.begin(), busRoutes.end());

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
        if (route.getName() == name && route.getDirection() == direction) {
            return route;
        }
    }
    throw std::invalid_argument("Nie znaleziono pasującej trasy.");

}

vector<BusStop> TimeTable::findMatchingBusStops(string busStopName) {
    vector<BusStop> matchingBusStops;
    for (auto route : routes) {
        vector<BusStop> busStops = route.getBusStops();
        for (auto stop : busStops) {
            if (stop.getName().find(busStopName) != string::npos && !route.contains(matchingBusStops, stop)) {
                matchingBusStops.push_back(stop);
            }
        }
    }
    return matchingBusStops;
}

vector<BusRoute> TimeTable::availableRoutes(BusStop stop) {
    vector<BusRoute> availableRoutes = allAvailableRoutes();
    vector<BusRoute> resultRoutes;
    for (auto route : availableRoutes) {
        if(route.contains(route.getBusStops(), stop)){
            resultRoutes.push_back(route);
        }
    }
    return resultRoutes;

}






