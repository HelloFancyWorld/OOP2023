#pragma once
#include <functional>
using namespace std;

class Click {
private:
    // TODO
    bool f_set;
    std::function<void()> f_click;

public:
    // TODO
    Click() : f_set(0)
    // TODO
    {
    }
    void setClickCommand(std::function<void()> f)
    // TODO
    {
        f_set = 1;
        f_click = f;
    }
    virtual void click()
    {
        if(f_set)
            f_click();
    }
};
class DoubleClick {
private:
    // TODO
    bool f_set;
    std::function<void()> f_click;
public:
    // TODO
    DoubleClick() : f_set(0){}
    // TODO
    void setDoubleClickCommand(std::function<void()> f)
    // TODO
    {
        f_set = 1;
        f_click = f;
    }
    virtual void doubleClick()
    {
        if(f_set)
            f_click();
    }
};