#pragma once

#include <string>
using namespace std;

class Cow
{
    public:
    string name;
    int least;
    int most;
    int output;
    int feed;
    int flag;   //0 havenot eaten, 1 no food,
                //2 not full, 4 full 

    Cow(string n, int l, int u, int m)
    : name(n), least(l), most(u), 
    output(m), feed(0), flag(0) {}
    Cow() : least(0), 
    most(0), output(0), feed(0), flag(0) {}
};