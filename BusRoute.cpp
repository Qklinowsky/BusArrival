#include "BusRoute.h"

BusRoute::BusRoute(const list<RouteSegment> &r, list<int> departureTimeMinutes) : route(r), departureTimeMinutes(departureTimeMinutes) {
}

BusRoute::BusRoute(const BusRoute& orig) {
}

BusRoute::~BusRoute() {
}

list<BusStop> BusRoute::getBusStops() {
    list<RouteSegment>::iterator it = route.begin();
    list<BusStop> allBusStops;
    while (it != route.end()) {
        allBusStops.push_back(it->getOrigin());
        it++;
    }
    allBusStops.push_back(route.end()->getDestination());
    return allBusStops;
}

list<int> BusRoute::getDepartureTime(BusStop& stop) {
    if (!contains(getBusStops(), stop)) {
        throw std::invalid_argument("This route doesn't contain this stop!");
    }
    list<RouteSegment>::iterator it = route.begin();

    if (it->getOrigin().getName() == stop.getName()) {
        return departureTimeMinutes;
    }
    int totalTimeTravel = 0;
    while (it != route.end()) {
        totalTimeTravel += it->getTravelTime();
        if (it->getDestination().getName() == stop.getName()) {
            break;
        }
        it++;
    }
    list<int>busStopDepartureTimes;
    for (auto departureTime : departureTimeMinutes) {
        int busStopDepartureTime = totalTimeTravel + departureTime;
        busStopDepartureTimes.push_back(busStopDepartureTime);
    }
    return busStopDepartureTimes;
}

bool BusRoute::contains(list<BusStop> busStops, BusStop stop) {
    list<BusStop>::iterator it = busStops.begin();
    while (it != busStops.end()) {
        if (it->getName() == stop.getName()) {
            return true;
        }
        it++;
    }
    return false;
}
