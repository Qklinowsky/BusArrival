#define BOOST_ALL_DYN_LINK
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <list>
#include "BusStop.h"
#include "BusRoute.h"
#include "TimeTable.h"
#include "DataImporter.h"
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

namespace logging = boost::log;
using namespace std;

BusRoute chooseRoute(vector<BusRoute> availableRoutes);
BusStop chooseDirection(BusRoute route, TimeTable table);
BusStop chooseBusStop(BusRoute route);
int chooseMenuOption();
BusStop findBusStop(TimeTable table);

void init() {
    logging::core::get()->set_filter
            (
            logging::trivial::severity >= logging::trivial::debug
            );
}

int main(int argc, char** argv) {
    init();
    DataImporter importer;
    list<BusRoute> wsyzsktieTrasy = importer.import("Lines");
    TimeTable timeTable = TimeTable(wsyzsktieTrasy);

    while (true) {
        int menuOption = chooseMenuOption();
        switch (menuOption) {
            case 2:
            {
                BusRoute route = chooseRoute(timeTable.allAvailableRoutes());
                BusStop direction = chooseDirection(route, timeTable);
                BusRoute foundRoute = timeTable.findRoute(route.getName(), direction);
                BusStop chosenStop = chooseBusStop(foundRoute);
                timeTable.showTimeTable(foundRoute, chosenStop);
            }
                break;
            case 1:
            {
                BusStop busStop = findBusStop(timeTable);
                vector<BusRoute> availableRoutes = timeTable.availableRoutes(busStop);
                BusRoute chosenRoute = chooseRoute(availableRoutes);
                BusStop chosenDirection = chooseDirection(chosenRoute, timeTable);
                BusRoute rightRoute = timeTable.findRoute(chosenRoute.getName(), chosenDirection);
                timeTable.showTimeTable(rightRoute, busStop);
                
            }
                break;
        }

        system("read -p' Press Enter to continue...' var"); //waiting for action
    }

    return 0;
}

BusRoute chooseRoute(vector<BusRoute> availableRoutes) {
    cout << "Wybierz linie z listy: \n";
    for (auto route : availableRoutes) {
        cout << "Linia " << route.getName() << endl;
    }
    string lineName;
    cin >> lineName;
    for (auto route : availableRoutes) {
        if (route.getName() == lineName) {
            return route;
        }
    }
    throw std::invalid_argument("There's no route for name: " + lineName);
}

BusStop chooseDirection(BusRoute route, TimeTable table) {

    cout << "Wybierz kierunek: \n";
    vector<BusStop> availableDestinations = table.availableDestinations(route.getName());
    int i = 1;
    for (auto destiantion : availableDestinations) {
        cout << i << " - Kierunek: " << destiantion.getName() << endl;
        i++;
    }
    int option;
    cin >> option;
    return availableDestinations.at(option - 1);

}

BusStop chooseBusStop(BusRoute route) {
    cout << "Wybierz przystanek: \n";
    vector<BusStop> busStops = route.getBusStops();
    int i = 1;
    for (auto stop : busStops) {
        cout << i << " - " << stop.getName() << endl;
        i++;
    }
    int option;
    cin >> option;
    return busStops.at(option - 1);
}

int chooseMenuOption() {
    int chosen;
    cout << "Wybierz opcje: \n";
    cout << "1 - Wybierz przystanek.\n 2 - Wybierz linie.\n";
    cin >> chosen;
    return chosen;
}

BusStop findBusStop(TimeTable table) {
    string busStopName;
    int i = 1;
    cout << "Podaj nazwe przystanku: \n";
    cin >> busStopName;
    vector<BusStop> matchingBusStops = table.findMatchingBusStops(busStopName);
    for (auto busStop : matchingBusStops) {
        cout << i << " - " << busStop.getName() << endl;
        i++;
    }
    int option;
    cout << "Wybierz przeystanek: \n";
    cin >> option;
    return matchingBusStops.at(option - 1);

}
