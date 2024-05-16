#pragma once
#include <iostream>
#include <string>
//#include <bits/stdc++.h>
#include "Fraction.h"
#include "calculate.h"

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}

long long abss(long long a)
{
    if (a > 0)
        return a;

    return -a;
}

struct Fraction
{
    long long up, down;
    Fraction(long long x)
    {
        up = x;
        down = 1;
    }
        Fraction()
    {
        up = 1;
        down = 1;
    }

    Fraction(const Fraction&a)
    {
        up = a.up;
        down = a.down;
    }

    void operator=(const Fraction &a){
        up = a.up;
        down = a.down;

    }

    Fraction(long long x, long long y)
    {
        up = x;
        down = y;
        if(y < 0){
            x *= -1;
            y *= -1;
        }
    }

    operator string(){
        if(down == 1){
            string a = to_string(up);
            return a;
        }
        string a = to_string(up) + "/" + to_string(down);
        return a;
    }
};

Fraction operator+(Fraction &a, Fraction &b)
{
    long long newup = a.up * b.down + a.down * b.up;
    long long newdown = a.down * b.down;
    if (newup != 0)
    {
        long long r = gcd(abss(newup), abss(newdown));
        newup /= r;
        newdown /= r;
        Fraction tmp(newup,newdown);
        return tmp;
    }
    Fraction temp(0,1);
    return temp;
}

Fraction operator-(Fraction &a, Fraction &b)
{    long long newup = a.up * b.down - a.down * b.up;
    long long newdown = a.down * b.down;
    if (newup != 0)
    {
        long long r = gcd(abss(newup), abss(newdown));
        newup /= r;
        newdown /= r;
        Fraction tmp(newup,newdown);
        return tmp;
    }
    Fraction temp(0,1);
    return temp;
}


Fraction operator*(Fraction &a, Fraction &b)
{    long long newup = a.up *  b.up;
    long long newdown = a.down * b.down;
    if (newup != 0)
    {
        long long r = gcd(abss(newup), abss(newdown));
        newup /= r;
        newdown /= r;
        Fraction tmp(newup,newdown);
        return tmp;
    }
    Fraction temp(0,1);
    return temp;

}

Fraction operator/(Fraction &a, Fraction &b)
{    long long newup = a.up *  b.down;
    long long newdown = a.down * b.up;

    if (newup != 0)
    {
        long long r = gcd(abss(newup), abss(newdown));
        newup /= r;
        newdown /= r;
        Fraction tmp(newup,newdown);
        return tmp;
    }
    Fraction temp(0,1);
    return temp;

}

