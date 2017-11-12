#include "RouteSegment.h"

RouteSegment::RouteSegment(BusStop& origin, BusStop& destination, int travelTime) :origin(origin), destination(destination), travelTime(travelTime) {   
}

RouteSegment::~RouteSegment() {
    
}

BusStop RouteSegment::getOrigin() {
    return origin;
}

BusStop RouteSegment::getDestination() {
    return destination;
}

int RouteSegment::getTravelTime() {
    return travelTime;
}





