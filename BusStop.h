#ifndef BUSSTOP_H
#define BUSSTOP_H
#include <iostream>

using namespace std;

class BusStop {
public:
    BusStop(const string& s);
    BusStop(const BusStop& orig);
    virtual ~BusStop();
    string getName();
private:
    string name;
    
    

};

#endif /* BUSSTOP_H */

