#pragma once
#include"Animal.h"

class Fish : public Animal{
    public:
    Fish(int n){
        if(n == 0){
            color = "Red";
        }else{
            color = "Blue";
        }
    }

        void swim(){
        cout << color <<" fish is swimming."<<endl;
    }
    void sing(){
              cout <<"Fish can not sing."<<endl;
    }
    ~Fish(){
        cout<<color <<" fish is gone."<<endl;
    }
};