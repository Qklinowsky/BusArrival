#ifndef DATAIMPORTER_H
#define DATAIMPORTER_H

#include<string>

#include "BusRoute.h"
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>

class DataImporter {
public:
    DataImporter();
    DataImporter(const DataImporter& orig);
    virtual ~DataImporter();
    BusRoute import(const std::string& routeFile);
private:

};

#endif /* DATAIMPORTER_H */

