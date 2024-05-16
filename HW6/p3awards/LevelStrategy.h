#pragma once

class LevelStrategy
{
    public:
        virtual LevelStrategy* GetClassType()
        {
            return this;
        }
};
class P1LStrategy : public LevelStrategy
{
    public:
    P1LStrategy* GetClassType()
    {
        return this;
    }
};

class P2LStrategy : public LevelStrategy
{
    public:
    P2LStrategy* GetClassType()
    {
        return this;
    }
};

class P3LStrategy : public LevelStrategy
{
    public:
    P3LStrategy* GetClassType()
    {
        return this;
    }
};