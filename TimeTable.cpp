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

