#include "BusStop.h"

BusStop::BusStop(const std::string& s) : name(s) {
}

BusStop::BusStop(const BusStop& orig) {
}

BusStop::~BusStop() {
}

string BusStop::getName() {
    return name;
}

