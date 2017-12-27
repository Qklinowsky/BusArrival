#ifndef BUSROUTE_H
#define BUSROUTE_H

#include <list>
#include "BusStop.h"
#include "RouteSegment.h"

#include <boost/date_time/posix_time/posix_time.hpp>

using namespace boost::posix_time;

using namespace std;

class BusRoute {
public:
    BusRoute(const string& name, const list<RouteSegment>& r, list<ptime> departureTimeMinutes);
    BusRoute(const BusRoute& orig);
    virtual ~BusRoute();
    void printRoute(BusStop& b);

    string getName();
    BusStop getDirection();
    list<BusStop> getBusStops();
    list<ptime> getDepartureTime(BusStop& stop);

private:
    list<RouteSegment> route;
    list <ptime> departureTimeMinutes;
    string name;

    bool contains(list<BusStop> busStops, BusStop stop);
};

#endif /* BUSROUTE_H */

