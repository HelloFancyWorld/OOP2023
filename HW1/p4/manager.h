#pragma once
#include <string>
#include "chef.h"
using namespace std;

struct Chefs
{
    public:
    int num;
    Chef chef;
    Chefs* next;
    Chefs(int _num, Chef _chef, Chef* next): num(_num), chef(_chef), next(nullptr) {};
}; 

class Manager
{
    public:
    int i = 0;
    Chefs* head;
    Chefs* current;
    Manager();
    void newChef(Chef chef);
    void order(string dish);
    void order(string dish, int chefID);
};

