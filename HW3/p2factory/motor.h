#pragma once
#include "vehicle.h"

class Motor : public Vehicle
{
    public:
    Motor(int num, string name);
    void describe();
    void sell();
}; 