#pragma once

#include <string>
#include "Cow.h"
using namespace std;

class Farm
{
    int n;
    int k = 0;
    Cow* cows;
    double production;
    
    public:
    void addCow(Cow cow);
    void supply(string name, int account);
    void startMeal();
    void produceMilk();
    double getMilkProduction() {return production;}
    Farm(int _n);
    ~Farm() {delete[] cows;}
};
