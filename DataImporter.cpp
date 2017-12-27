#include "DataImporter.h"
#include "BusRoute.h"
#include <sstream>
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>

DataImporter::DataImporter() {
}

DataImporter::DataImporter(const DataImporter& orig) {
}

DataImporter::~DataImporter() {
}

BusRoute DataImporter::import(const std::string& routeFile) {
    std::ifstream infile(routeFile);

    bool isRoute = false;
    string line;
    BusStop* previousBusStop = NULL;
    BusStop* currentBusStop = NULL;
    list<RouteSegment> route;
    while (!std::getline(infile, line).eof()) {
        if (line == "TRASA") {
            isRoute = true;
            continue;

        } else if (line == "/TRASA") {
            isRoute = false;
            continue;
        }
        if (isRoute) {
            std::vector<std::string> tokens;
            boost::split(tokens, line, [](char c) {
                return c == '\t';
            });
            currentBusStop = new BusStop(tokens.at(0));

            if (previousBusStop) {
                int sectionTime = std::stoi(tokens.at(1));
                route.push_back(RouteSegment(*previousBusStop, *currentBusStop, sectionTime));
            }
            previousBusStop = currentBusStop;

        }
    }
    delete currentBusStop;

    list<int> departureTimes;
    departureTimes.push_back(240);
    departureTimes.push_back(440);
    
    BusRoute busRoute = BusRoute("1", route, departureTimes);
    return busRoute;
}

list<RouteSegment> readSegment(std::string& line) {

}


