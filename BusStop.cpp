#include "BusStop.h"

BusStop::BusStop(const std::string& s) :name(s) {
    
}

BusStop::~BusStop() {
}

std::string BusStop::getName() {
    return name;
}

bool operator== (BusStop lhs, BusStop rhs) {
    if(lhs.getName() == rhs.getName()) {
        return true;
    }
    return false;
} 
