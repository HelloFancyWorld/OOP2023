#pragma once

#include "func.h"

class CompFunc : public Func{
private:
    // Todo
    // 声明成员变量
    Func *para_outer;
    Func *para_inner;

public:
    CompFunc(Func *outer, Func* inner) : 
        para_outer(outer), para_inner(inner) {}
    // compute f(g(x))
    // Todo
    // 请参照指数函数类(ExpFunc)实现一个复合函数类
    // 并且要求，传入的参数的析构在该类被析构时同时析构
    double getPoint(double point){
        return para_outer->getPoint(para_inner->getPoint(point));
    }
    ~CompFunc() {
        delete para_inner;
        delete para_outer;
    }
};