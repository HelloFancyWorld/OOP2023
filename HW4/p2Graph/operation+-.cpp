#include "operation+-.h"

void Operation_plus::calc()
{
    OperationNodeTwo::calc();
}

void Operation_plus::UpdateValue()
{
    value_ = input1->value() + input2->value();
}

void Operation_minus::calc()
{
    OperationNodeTwo::calc();
}

void Operation_minus::UpdateValue()
{
    value_ = input1->value() - input2->value();
}