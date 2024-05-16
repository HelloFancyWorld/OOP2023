#pragma once
#include <iostream>
#include <string>
//#include <bits/stdc++.h>
#include "Fraction.h"
#include "calculate.h"

using namespace std;

template <typename T>
class calculate
{
public:
    char exp;
    long long x;
    long long y;
    long long z;
    T ans ;
    /*
    A 类表达式：x×x+y×y+z×zx×x+y×y+z×z；

    B 类表达式：x×y+y÷z−x×zx×y+y÷z−x×z；

    C 类表达式：y×3×z−x×z÷(y−2)−x×y÷(z+1)y×3×z−x×z÷(y−2)−x×y÷(z+1)；
    */
    calculate(char exp_, int x_, int y_, int z_)
    {
        exp = exp_;
        x = x_;
        y = y_;
        z = z_;
    }
    calculate(calculate &&a){
        exp = a.exp;
        x = a.x;
        y = a.y;
        z = a.z;
        ans = a.ans;
    }
    void cal()
    {
        if (exp == 'A')
        {
            //ans = x * x + y * y + z * z;
            T temp1 = x;
            T temp2 = y;
            T temp3 = z;
            T temp4 = temp1 * temp1;
            T temp5 = temp2 * temp2;
            T temp6 = temp3 * temp3;
            T t7 = temp4 + temp5;
            ans = t7 + temp6;
        }
        if (exp == 'B')
        {
            //ans = x * y + y / z - x * z;
            T temp1 = x;
            T temp2 = y;
            T temp3 = z;
            T temp4 = temp1 * temp2;
            T temp5 = temp2 / temp3;
            T temp6 = temp1 * temp3;
            T temp7 = temp4 + temp5;
            ans = temp7 - temp6;
        }
        if (exp == 'C')
        {

        /*    T tx = x;
            T ty = y;
            T tz = z;*/

            T temp1 = y * 3 * z;
            T temp2 = y - 2;
            T temp3 = x * z ;
            T temp35 = temp3/temp2;

            T temp4 = z + 1;
            T temp5 = x * y ;
            T temp6 = temp5/temp4;
            
            T temp7 = temp1 - temp35;
            //ans = y * 3 * z - x * z / (y - 2) - x * y / (z + 1);
            ans = temp7 - temp6;
        }
    }

    string output(){
        cal();
    string a = ans;
    return a;
    }
};

template <typename T>
ostream &operator<<(ostream &out, calculate<T> a)
{
    
    out << a.output();
    return out;
}

template<>
string calculate<int>::output()
{
    cal();
    string a = to_string(ans);
    return a;
}
/*

template<>
string calculate<Fraction>::output()
{
    string a = ans;
    return a;
}
*/