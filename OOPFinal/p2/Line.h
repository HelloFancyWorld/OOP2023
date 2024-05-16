#pragma once

template<typename T>
class Line
{
    public:
    T k, b;
    Line(T x, T y):k(x), b(y){}
    Line(T x):k(x), b(0){}
    bool intersect(const Line &);
    void show();
    bool operator<(const Line &);
};