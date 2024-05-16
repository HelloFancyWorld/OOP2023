#pragma once

class PerformStrategy
{
    public:
        double _perform;
        PerformStrategy(double perform) : _perform(perform) {}
        PerformStrategy() : _perform(0) {}
        virtual PerformStrategy* GetClassType()
        {
            return this;
        }
};
class sPerformStrategy : public PerformStrategy
{
    public:
    sPerformStrategy(double perform) : PerformStrategy(perform) {}
    sPerformStrategy() : PerformStrategy() {}
    sPerformStrategy* GetClassType()
    {
        return this;
    }
};

class mPerformStrategy : public PerformStrategy
{
    public:
    mPerformStrategy(double perform) : PerformStrategy(perform) {}
    mPerformStrategy() : PerformStrategy() {}
    mPerformStrategy* GetClassType()
    {
        return this;
    }
};

class lPerformStrategy : public PerformStrategy
{
    public:
    lPerformStrategy(double perform) : PerformStrategy(perform) {}
    lPerformStrategy() : PerformStrategy() {}
    lPerformStrategy* GetClassType()
    {
        return this;
    }
};