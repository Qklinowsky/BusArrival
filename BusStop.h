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
    friend bool operator== (BusStop lhs, BusStop rhs);
};

#endif /* BUSSTOP_H */

