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
    virtual ~BusRoute();
    void printRoute(BusStop& b);

    string getName() const;
    BusStop getDirection();
    vector<BusStop> getBusStops();
    list<ptime> getDepartureTime(BusStop& stop);
    bool operator< (const BusRoute& other) const;

private:
    list<RouteSegment> route;
    list <ptime> departureTimesFromOrigin;
    string name;

    bool contains(vector<BusStop> busStops, BusStop stop);
};

#endif /* BUSROUTE_H */

