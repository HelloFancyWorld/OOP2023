#include <iostream>
#include <list>
#include <vector>
#include "compare.h"
#include "sortlevel.h"
using namespace std;

Compare<vector<int>> make_comp(list<sort_level> sortlevels) 
{
    // todo
    vector<function<bool(vector<int>, vector<int>)>> comparators;
    for (auto &level : sortlevels) 
    {
        auto comp = [level](vector<int> a, vector<int> b) 
        {
            if (level.order == ASCEND) 
            {
                return a[level.column - 1] < b[level.column - 1];
            } 
            else
            {
                return a[level.column - 1] > b[level.column - 1];
            } 
        };
        comparators.push_back(comp);
    }
    return Compare<vector<int>>(comparators);
}


// 5 4 3
// 1 2 3 4
// 0 2 3 4
// 1 2 4 4
// 1 2 3 3
// 1 2 2 5
// 1 d
// 3 d
// 4 a
