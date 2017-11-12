#include "BusStop.h"

BusStop::BusStop(const std::string& s) :name(s) {
    
}

BusStop::~BusStop() {
}

std::string BusStop::getName() {
    return name;
}

