#ifndef DATAIMPORTER_H
#define DATAIMPORTER_H

#include<string>

#include "BusRoute.h"

class DataImporter {
public:
    DataImporter();
    DataImporter(const DataImporter& orig);
    virtual ~DataImporter();
    BusRoute import(const std::string& routeFile);
private:

};

#endif /* DATAIMPORTER_H */

