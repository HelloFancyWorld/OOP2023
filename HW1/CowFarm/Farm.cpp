#include "Farm.h"

Farm::Farm(int _n) : n(_n), production(0)
{
    cows = new Cow[n];
}

void Farm::addCow(Cow cow)
{
    cows[k] = cow;
    k++;
}

void Farm::supply(string name, int account)
{
    for(int i = 0; i < n; i++)
    {
        if(cows[i].name == name)
        {
            cows[i].feed += account;
            return;
        }
    }
}

void Farm::startMeal()
{
    for(int i = 0; i < n; i++)
    {
        int j = cows[i].feed;
        if(j >= cows[i].most)
        {
            cows[i].feed -= cows[i].most;
            cows[i].flag = 4;
        }
        else if(j >= cows[i].least)
        {
            cows[i].feed = 0;
            cows[i].flag = 4;
        }
        else if(j > 0)
        {
            cows[i].feed = 0;
            cows[i].flag = 3;
        }
        else
        {
            cows[i].flag = 2;
        }
    }
}

void Farm::produceMilk()
{
    for(int i = 0; i < n; i++)
    {
        int j = cows[i].flag;
        if(j == 4)
        {
            production += cows[i].output;
        }
        else if(j == 3)
        {
            production += (cows[i].output / 2.0);
        }
        cows[i].flag = 1;
    }
}