#pragma once
#include "vehicle.h"

class Car : public Vehicle
{
    public:
    Car(int num, string name);
    void describe();
}; 