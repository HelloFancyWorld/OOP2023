#pragma once
#include "LevelStrategy.h"
#include "PerformStrategy.h"
#include <typeinfo>

class Calculator
{
    private:
        LevelStrategy _ls;
        int base;
        PerformStrategy _ps;
        double perform;
    public : 
        Calculator(LevelStrategy* a, PerformStrategy* b)
        {
            if(typeid(*(a->GetClassType())) == typeid(P1LStrategy))
            {
                base = 2000;
            }
            else if(typeid(*(a->GetClassType())) == typeid(P2LStrategy))
            {
                base = 5000;
            }
            else if(typeid(*(a->GetClassType())) == typeid(P3LStrategy))
                base = 10000;
            perform = b->_perform;
        }
        int get_base()
        {
            return base;
        }
        int get_total(int _base)
        {
            if(perform >= 0 && perform < 0.5)
                return _base + 1000;
            else if(perform >= 0.5 && perform < 0.8)
            {
                return _base + _base * perform;
            }
            else
                return _base + 2 * _base * perform;
        }
};