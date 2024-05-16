#include "vehicle.h"

Vehicle::Vehicle(int num, string name) : engine(name), wheels(num) 
{
}

void Vehicle::describe()
{
    cout << "Finish building a vehicle with "
    << wheels.get_num() << " wheels and a " << 
    engine.get_name() << " engine." << endl;
    cout << "A vehicle with "
    << wheels.get_num() << " wheels and a " << 
    engine.get_name() << " engine." << endl;
}