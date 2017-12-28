#include <boost/log/trivial.hpp>
#include "BusRoute.h"

BusRoute::BusRoute(const string& name, const list<RouteSegment> &r, list<ptime> departureTimeMinutes) : name(name), route(r), departureTimesFromOrigin(departureTimeMinutes) {
}

BusRoute::~BusRoute() {
}

vector<BusStop> BusRoute::getBusStops() {
    list<RouteSegment>::iterator it = route.begin();
    vector<BusStop> allBusStops;
    while (it != route.end()) {
        allBusStops.push_back(it->getOrigin());
        it++;
    }
    allBusStops.push_back(route.back().getDestination());
    return allBusStops;
}

list<ptime> BusRoute::getDepartureTime(BusStop& stop) {
    if (!contains(getBusStops(), stop)) {
        throw std::invalid_argument("This route doesn't contain this stop!");
    }
    list<RouteSegment>::iterator it = route.begin();

    if (it->getOrigin().getName() == stop.getName()) {
        return departureTimesFromOrigin;
    }
    int totalTimeTravel = 0;
    while (it != route.end()) {
        totalTimeTravel += it->getTravelTime();
        if (it->getDestination().getName() == stop.getName()) {
            break;
        }
        it++;
    }
    list<ptime> busStopDepartureTimes;
    for (auto departureTime : departureTimesFromOrigin) {
        BOOST_LOG_TRIVIAL(debug) << "Departure time from origin " << departureTime << ", totalTimeTravel=" << totalTimeTravel;
        ptime busStopDepartureTime = ptime(departureTime + minutes(totalTimeTravel)); //todo add minutes to date
        BOOST_LOG_TRIVIAL(debug) << "Departure time for bus stop " << stop.getName() << ":" << busStopDepartureTime;
        busStopDepartureTimes.push_back(busStopDepartureTime);
    }
    return busStopDepartureTimes;
}

bool BusRoute::contains(vector<BusStop> busStops, BusStop stop) {
    vector<BusStop>::iterator it = busStops.begin();
    while (it != busStops.end()) {
        if (it->getName() == stop.getName()) {
            return true;
        }
        it++;
    }
    return false;
}

string BusRoute::getName() const {
    return name;
}

BusStop BusRoute::getDirection() {
    return route.back().getDestination();
}

void BusRoute::printRoute(BusStop& startingStop) {
    std::cout << "Trasa: " << endl;
    vector<BusStop> stops = getBusStops();
    bool print = false;
        int i = 1;
    for (auto stop : stops) {
        if (startingStop == stop) {
            print = true;
        }
        if(print){
            std::cout << i << " - " << stop.getName() << endl;
        }
        i++;
    }
}

bool BusRoute::operator<(const BusRoute& other) const {
    int thisName = std::stoi(name);
    int otherName = std::stoi(other.getName());
    return thisName < otherName;
}