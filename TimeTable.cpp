#include <string>
#include "TimeTable.h"

TimeTable::TimeTable(list<BusRoute> routes) : routes(routes) {
}

TimeTable::~TimeTable() {
}

void TimeTable::showTimeTable(BusRoute& route, BusStop& stop) {
    string routeName = route.getName();
    std::cout << "Rozkład jazdy dla lini: " << routeName << endl ;
    std::cout << "Dla przystanku: " <<stop.getName() << endl ;
    std::cout << "W kierunku: " << route.getDirection().getName() << endl;
    
    list<int> busStopDepartureTimes = route.getDepartureTime(stop);
    for (int departureTime : busStopDepartureTimes) {
        std::cout << formatTime(departureTime) << endl;
    }
}

string TimeTable::formatTime(int hourInMinutes) {
    int hours = hourInMinutes / 60;
    int minutes = hourInMinutes % 60;

    return std::to_string(hours) + ":" + to_string(minutes);
}
