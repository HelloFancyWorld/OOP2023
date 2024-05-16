#include "Line.h"
#include <iostream>
using namespace std;

template<typename T>
bool Line<T>::intersect(const Line &newline)
{
    if(k != newline.k)
        return true;
    else if(b == newline.k)
        return true;
    else
        return false;
}

template<typename T>
void Line<T>::show()
{
    cout << k << ',' << b << endl;
}

template<typename T>
bool Line<T>::operator<(const Line &newline)
{
    return k < newline.k;
}