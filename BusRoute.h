#ifndef BUSROUTE_H
#define BUSROUTE_H

#include <list>
#include "BusStop.h"

using namespace std;


class BusRoute {
public:
    BusRoute(const list<BusStop>& r);
    BusRoute(const BusRoute& orig);
    virtual ~BusRoute();
private:
    list<BusStop> route;
    

};

#endif /* BUSROUTE_H */

