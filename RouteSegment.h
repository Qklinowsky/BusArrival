#ifndef ROUTESEGMENT_H
#define ROUTESEGMENT_H

#include "BusStop.h"

class RouteSegment {
public:
    RouteSegment(BusStop& origin, BusStop& destination, int travelTime);
    virtual ~RouteSegment();

    BusStop getOrigin();
    BusStop getDestination();
    int getTravelTime();
private:
    BusStop origin;
    BusStop destination;
    int travelTime;

};
#endif /* ROUTESEGMENT_H */