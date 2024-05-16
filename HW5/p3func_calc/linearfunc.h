#pragma once

#include "func.h"

class LinearFunc : public Func{
private:
    double para_a, para_b;

public:
    LinearFunc(double a, double b) : para_a(a), para_b(b) {}
    // Todo
    // 请参照指数函数类(ExpFunc)实现一个一次函数类
    // f(x) = ax + b;
    double getPoint(double point){
        return point * para_a + para_b;
    }
};