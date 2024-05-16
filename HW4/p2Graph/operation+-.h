#pragma once
#include "operation.h"

class Operation_plus : public OperationNodeTwo
{
    public:
    Operation_plus(string name, Node *x1, Node *x2) : OperationNodeTwo(name, x1, x2) {}
    void calc() override;
    void UpdateValue() override;
    ~Operation_plus() {}
};



class Operation_minus : public OperationNodeTwo
{
    public:
    Operation_minus(string name, Node *x1, Node *x2) : OperationNodeTwo(name,x1,x2){}
    void calc() override;
    void UpdateValue() override;
    ~Operation_minus(){}
};