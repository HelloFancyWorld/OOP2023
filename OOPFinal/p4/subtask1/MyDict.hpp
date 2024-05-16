#pragma once
#include <map>
#include "HitStatsResult.hpp"
using namespace std;
template<class Key, class Value> 
class MyDict
{
    private:
        map<Key, Value> maps;
        int hit;
        int miss;
    public:
        MyDict() : hit(0), miss(0) {}
        Value &operator[](Key key)
        {
            typename map<Key, Value>::iterator it;
            it = maps.find(key);
            if(it != maps.end())
            {
                hit++;
                return it->second;
            }
            else
            {
                miss++;
                Value *value = new Value();
                maps.insert(make_pair<Key, Value>(key, value));
                return *value;
            }
        }
        HitStatsResult hitStats() const
        {
            return HitStatsResult(hit, miss);
        }
        int size() const
        {
            return maps.size();
        }
        void clear()
        {
            maps.clear();
            hit = 0;
            miss = 0;
        }
};

