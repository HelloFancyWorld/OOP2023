#pragma once
#include "window.h"
#include <iostream>
#include <memory>
#include <list>
using namespace std;

class ClearAll {
    // TODO
    list<shared_ptr<Checkbox>> _checkbox;

public:
    // TODO
    ClearAll(list<shared_ptr<Checkbox>> checkbox) : _checkbox(checkbox) {}
    void operator()()
    {
        list<shared_ptr<Checkbox>>::iterator iter;
        for(iter = _checkbox.begin(); iter != _checkbox.end(); iter++)
        {
            (*iter)->state = 0;
        }
    }
};

class SelectAll {
    // ...
    list<shared_ptr<Checkbox>> _checkbox;
public:
    // TODO
    SelectAll(list<shared_ptr<Checkbox>> checkbox): _checkbox(checkbox) {}
    void operator()()
    {
        list<shared_ptr<Checkbox>>::iterator iter;
        for(iter = _checkbox.begin(); iter != _checkbox.end(); iter++)
        {
            (*iter)->state = 1;
        }
    }
};

class Submit {
    // ...
    list<shared_ptr<Checkbox>> _checkbox;
public:
    // TODO
    Submit(list<shared_ptr<Checkbox>> checkbox): _checkbox(checkbox) {}
    void operator()()
    {
        list<shared_ptr<Checkbox>>::iterator iter;
        for(iter = _checkbox.begin(); iter != _checkbox.end(); iter++)
        {
            if((*iter)->state == 1)
                cout << (*iter)->getName() << " is selected" << endl;
            else 
                cout << (*iter)->getName() << " is not selected" << endl;
        }
    }
};