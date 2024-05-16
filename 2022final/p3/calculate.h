#pragma once
#include <iostream>
using namespace std;

template <typename T>
int calculate(char expressionType, int x, int y, int z) 
{
    if (expressionType == 'A')
    {
        return x * x + y * y + z * z;
    }
    else if (expressionType == 'B')
    {
        return x * y + y / z - x * z;
    }
    else
    {
        return y * 3 * z - (x * z) / (y - 2) - x * y / (z + 1);
    }
}