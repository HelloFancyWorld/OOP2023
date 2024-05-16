#pragma once

#include "func.h"

class CombFunc : public Func{
private:
    // Todo
    // 声明成员变量
    Func *para_a;
    Func *para_b;
    double para_c, para_d;

public:
    CombFunc(Func *fun_1, Func *fun_2, double coe_1, double coe_2)
        : para_a(fun_1), para_b(fun_2), para_c(coe_1), para_d(coe_2) {}
    // compute a * f(x) + b * g(x)
    // Todo
    // 请参照指数函数类(ExpFunc)实现一个组合函数类
    // 并且要求，传入的参数的析构在该类被析构时同时析构
    double getPoint(double point){
        return para_c * para_a->getPoint(point) + 
            para_d * para_b->getPoint(point);
    }
    ~CombFunc() {
        delete para_a;
        delete para_b;
    }
};