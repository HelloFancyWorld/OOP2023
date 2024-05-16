#pragma once
#include <memory>
#include <list>
#include <stack>
#include "event.h"

using namespace std;

class Window;

class Widget {
    string _name;
    Window* _parent;
public:
    Widget(string name) :_name(name), _parent(nullptr) {}
    string getName() const { return _name; }
    Window* getParent() const { return _parent; }
    void setParent(Window * parent) {_parent = parent;}
    virtual ~Widget() {}
};

class Button :public Widget, public Click, public DoubleClick {
public:
    Button(string name) :Widget(name) {}
};

class Checkbox :public Widget, public Click {
    // TODO
    public:
        bool state; //1 selected
        Checkbox(string name) : Widget(name) {}
        void click()
        {
            if(state) state = 0;
            else
                state = 1;
        }
};

class Window {

private:
    list<shared_ptr<Widget>> Widgets;
    // TODO
    
public:
    // TODO
    shared_ptr<Widget> getPointerByName(string name)
    // TODO
    {
        list<shared_ptr<Widget>>::iterator iter;
        for(iter = Widgets.begin(); iter != Widgets.end(); iter++)
        {
            if((*iter)->getName() == name)
                return (*iter);
        }
        return nullptr;
    }
    Widget& getElementByName(string name)
    // TODO
    {
        list<shared_ptr<Widget>>::iterator iter;
        for(iter = Widgets.begin(); iter != Widgets.end(); iter++)
        {
            if((*iter)->getName() == name)
                return (**iter);
        }
        return **iter;
    }
    bool addElement(shared_ptr<Widget> w)
    // TODO
    {
        if(getPointerByName(w->getName()) != nullptr)
            return false;
        Widgets.push_back(w);
        return true;
    }
    bool undo(){}
};
