#pragma once
#include "Animal.h"
#include <iostream>
using namespace std;
class Fish : public Animal
{
    public:
    string color;
    Fish(int _color)
    {
        if(_color == 0)
            color = "Red";
        else
            color = "Blue";
    }
    void sing()
    {
        cout << "Fish can not sing." << endl;
    }
    void swim()
    {
        cout << color << " fish is swimming." << endl;
    }
    virtual ~Fish() 
    {
        cout << color << " fish is gone." << endl;
    }
};