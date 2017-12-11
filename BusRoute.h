#ifndef BUSROUTE_H
#define BUSROUTE_H

#include <list>
#include "BusStop.h"
#include "RouteSegment.h"

using namespace std;


class BusRoute {
public:
    BusRoute(const string& name, const list<RouteSegment>& r, list<int> departureTimeMinutes);
    BusRoute(const BusRoute& orig);
    virtual ~BusRoute();
    void printRoute(BusStop& b);

    string getName();
    BusStop getDirection();
    list<BusStop> getBusStops();
    list<int>getDepartureTime(BusStop& stop);

private:
    list<RouteSegment> route;
    list <int> departureTimeMinutes;
    string name;
    
    bool contains(list<BusStop> busStops, BusStop stop);
};

#endif /* BUSROUTE_H */

