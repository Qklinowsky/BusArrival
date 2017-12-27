#include "DataImporter.h"
#include "BusRoute.h"
#include <sstream>
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/local_time_adjustor.hpp>
#include <boost/regex.hpp>
#include <boost/algorithm/string/regex.hpp>

using namespace boost::posix_time;
using namespace boost::gregorian;

DataImporter::DataImporter() {
}

DataImporter::DataImporter(const DataImporter& orig) {
}

DataImporter::~DataImporter() {
}

BusRoute DataImporter::import(const std::string& routeFile) {
    std::ifstream infile(routeFile);

    bool isRoute = false;
    bool isHours = false;
    string line;
    BusStop* previousBusStop = NULL;
    BusStop* currentBusStop = NULL;
    string lineName;
    list<RouteSegment> route;
    list<ptime> departureTimes;
    while (!std::getline(infile, line).eof()) {

        if (boost::starts_with(line, "Linia:")) {
            lineName = boost::algorithm::erase_first_copy(line, "Linia: ");
        }
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
        if (line == "GODZINY") {
            isHours = true;
            continue;
        } else if (line == "/GODZINY") {
            isHours = false;
            continue;
        }
        if (isHours) {
            std::vector<std::string> splitVector;
            boost::split_regex(splitVector, line, boost::regex( ": " ));
            int hour = std::stoi(splitVector.at(0));
            std::string minutesStr = splitVector.at(1);
            std::vector<std::string> minutesVector;
            boost::split(minutesVector, minutesStr, boost::is_space());
            for (auto minute : minutesVector) {
                int minute_int = std::stoi(minute);
                ptime now = second_clock::local_time();
                ptime fullTime = ptime(now.date(), hours(hour) + minutes(minute_int));
                departureTimes.push_back(fullTime);
            }

        }
    }

    delete currentBusStop;



    BusRoute busRoute = BusRoute(lineName, route, departureTimes);
    return busRoute;
}

list<RouteSegment> readSegment(std::string& line) {

}


