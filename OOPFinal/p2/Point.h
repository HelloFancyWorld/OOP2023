#pragma once
#include "Line.h"
template<typename T>
class Point
{
    public:
    T x, y;
    Point(T a, T b):x(a), y(b){}
    void move(T dx, T dy);
    void show();
    bool check(Line<T> const &l);
};