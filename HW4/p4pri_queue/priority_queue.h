#pragma once

#include "abstract_compare.h"
#include <vector>
using namespace std;

template<typename T> 
class PriorityQueue {
public:
    vector<T> pqueue;
    AbstractCompare<T>* cmp;
    PriorityQueue(AbstractCompare<T>* _cmp);
    ~PriorityQueue();
    bool empty();
    int size();
    void push(T element);
    void pop();
    T top();
};
template<typename T>
bool PriorityQueue<T>::empty()
{
    return pqueue.empty();
}

template<typename T>
int PriorityQueue<T>::size()
{
    return pqueue.size();
}

template<typename T>
void PriorityQueue<T>::push(T element)
{
    if (pqueue.size() == 0)
    {
        pqueue.push_back(element);
    }
    else
    {
        bool flag = 1;
        for (int i = 0; i < pqueue.size(); i++)
        {
            if (cmp->compare(element, pqueue[i]))
            {
                pqueue.insert(pqueue.begin() + i, element);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            pqueue.push_back(element);
        }
    }
}

template<typename T>
void PriorityQueue<T>::pop()
{
    pqueue.pop_back();
}

template<typename T>
T PriorityQueue<T>::top()
{
    return pqueue[pqueue.size() - 1];
}

template<typename T>
PriorityQueue<T>::PriorityQueue(AbstractCompare<T>* _cmp) :
    cmp(_cmp) {}

template<typename T>
PriorityQueue<T>::~PriorityQueue() {}