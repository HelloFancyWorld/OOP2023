#include "chef.h"
#include <iostream>
using namespace std;

Chef::Chef(std::string _name, std::string _signatureDish)
: name(_name), signatureDish(_signatureDish) {}

bool Chef::isSignatureDish(std::string dish)
{
    return (signatureDish == dish);
}

void Chef::cook(std::string dish)
{
    if(isSignatureDish(dish))
        cout << name << " made an awesome " << dish << endl;
    else
        cout << name << " made a plain " << dish << endl;
}