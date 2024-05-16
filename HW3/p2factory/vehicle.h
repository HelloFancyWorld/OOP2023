#pragma once
#include "wheel.h"
#include "engine.h"

class Vehicle
{
    public:
    Engine engine;
    Wheel wheels;
    Vehicle(int num, string name);
    void describe();
};