#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <list>
#include "BusRoute.h"

class TimeTable {
public:
    TimeTable(list<BusRoute> routes);
    virtual ~TimeTable();

    void showTimeTable(BusRoute& route, BusStop& stop);
    vector<BusRoute> allAvailableRoutes();
    vector<BusRoute> availableRoutes(BusStop stop);
    vector<BusStop> availableDestinations(string lineName);
    vector<BusStop> availableBusStops(string lineName, BusStop destination);
    BusRoute findRoute(string name, BusStop direction);
    vector<BusStop> findMatchingBusStops(string busStopName);
    

private:
    list<BusRoute> routes;
    bool contains(vector<BusRoute> routes, BusRoute route);
};

#endif /* TIMETABLE_H */

