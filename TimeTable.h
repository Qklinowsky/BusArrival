#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <list>
#include "BusRoute.h"

class TimeTable {
public:
    TimeTable(list<BusRoute> routes);
    virtual ~TimeTable();
    
    void showTimeTable(BusRoute& route, BusStop& stop);
    
private:
    list<BusRoute> routes;
    
    string formatTime(int hourInMinutes);
};

#endif /* TIMETABLE_H */

