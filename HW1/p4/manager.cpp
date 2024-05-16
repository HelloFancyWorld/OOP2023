#include "manager.h"

Manager::Manager() : head(nullptr), current(nullptr) {}
void Manager::newChef(Chef chef)
{
    if(head == nullptr)
    {
        head = new Chefs(i, chef, nullptr);
        current = head;
        i++;
    }
    else
    {
        Chefs* newchef = new Chefs(i, chef, nullptr);
        current->next = newchef;
        current = newchef;
        i++;
    }
}

void Manager::order(string dish)
{
    Chefs* it = head;
    while(it != nullptr)
    {
        if((*it).chef.isSignatureDish(dish))
        {
            (*it).chef.cook(dish);
            return;
        }
        it = it->next;
    }
    if (head != nullptr)
    {
        head->chef.cook(dish);
    }
    return;
}

void Manager::order(string dish, int chefID)
{
    Chefs* it = head;
    for(int i = 0; i < chefID; i++)
    {
        it = it->next;
    }
    (*it).chef.cook(dish);
}