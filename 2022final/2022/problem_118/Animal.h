#pragma once
#include<string>
#include<iostream>
using namespace std;
class Animal{
public:
    string color;
    virtual void sing() = 0;
    virtual void swim() = 0;
    virtual ~Animal() = 0;
};

Animal::~Animal(){}