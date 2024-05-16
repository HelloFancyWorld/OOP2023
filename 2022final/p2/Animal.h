#pragma once


class Animal
{
    public:
    virtual void sing() = 0;
    virtual void swim() = 0;
    virtual ~Animal() = 0;
};
Animal::~Animal()
{}