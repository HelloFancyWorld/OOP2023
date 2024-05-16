#pragma once
#include "Animal.h"
#include <iostream>
using namespace std;
class Bird : public Animal
{
    public:
    string color;
    Bird(int _color)
    {
        if(_color == 0)
            color = "Red";
        else
            color = "Blue";
    }
    void swim()
    {
        cout << "Bird can not swim." << endl;
    }
    void sing()
    {
        cout << color << " bird is singing." << endl;
    }
    virtual ~Bird() 
    {
        cout << color << " bird is gone." << endl;
    }
};