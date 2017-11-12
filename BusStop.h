#ifndef BUSSTOP_H
#define BUSSTOP_H
#include <iostream>
#include <string>

class BusStop {
public:
    BusStop(const std::string& s);
    virtual ~BusStop();
    std::string getName();
private:
    std::string name;
};

#endif /* BUSSTOP_H */

