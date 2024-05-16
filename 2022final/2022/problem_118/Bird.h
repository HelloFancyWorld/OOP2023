#pragma once
#include"Animal.h"

class Bird : public Animal{
    public:
    Bird(int n){
        if(n == 0){
            color = "Red";
        }else{
            color = "Blue";
        }
    }
    void sing(){
        cout << color <<" bird is singing."<<endl;
    }
    void swim(){
              cout <<"Bird can not swim."<<endl;
    }
    ~Bird(){
        cout<<color <<" bird is gone."<<endl;
    }
};