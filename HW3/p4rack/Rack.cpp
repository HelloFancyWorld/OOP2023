#include "Rack.h"

Rack::Rack(const Rack& _rack)
{
    for (int i = 0; i < _rack.goods.size(); i++)
    {
        goods.push_back(_rack.goods[i]);
    }
}

void Rack::operator+=(const int good)
{
    goods.push_back(good);
}

void Rack::operator+=(const Rack& rack)
{
    Rack _rack(rack);
    for (int i = 0; i < _rack.goods.size(); i++)
    {
        goods.push_back(_rack.goods[i]);
    }
    //_rack.~Rack();
}

ostream& operator<<(ostream& out, const Rack& rack)
{
    for (int i = 0; i < rack.goods.size(); i++)
    {
        out << ' ' << rack.goods[i];
    }
    return out;
}

int Rack::operator()(const int index) const
{
    int count = 0;
    for (int i = 0; i < goods.size(); i++)
    {
        if (goods[i] == index)
            count++;
    }
    return count;
}

void Rack::operator~()
{
    vector<int> temp;
    for (int i = goods.size() - 1; i >= 0; i--)
    {
        temp.push_back(goods[i]);
    }
    for (int i = 0; i < goods.size(); i++)
    {
        goods[i] = temp[i];
    }
}

void Rack::operator--()
{
    goods.erase(goods.begin());
}

void Rack::operator--(int)
{
    goods.pop_back();
}

Rack operator , (const Rack& a, const Rack& b)
{
    Rack c(a);
    c += b;
    return c;
}

Rack operator , (const Rack& a, const int b)
{
    Rack c(a);
    c += b;
    return c;
}
Rack operator , (const int b, const Rack& a)
{
    Rack c(a);
    c.goods.insert(c.goods.begin(), b);
    return c;
}

bool Rack::operator<(const Rack& b)
{
    return (goods.size() < b.goods.size());
}
bool Rack::operator==(const Rack& b)
{
    return (goods.size() == b.goods.size());
}
bool Rack::operator>(const Rack& b)
{
    return (goods.size() > b.goods.size());
}

Rack operator&(const Rack& a, const Rack& b)//wrong
{
    vector<int> temp_a, temp_b;
    Rack result;
    for (int i = 0; i < a.goods.size(); i++)
    {
        if (find(temp_a.begin(), temp_a.end(), a.goods[i]) == temp_a.end())
        {
            temp_a.push_back(a.goods[i]);
        }
    }
    for (int i = 0; i < b.goods.size(); i++)
    {
        if (find(temp_b.begin(), temp_b.end(), b.goods[i]) == temp_b.end())
        {
            temp_b.push_back(b.goods[i]);
        }
    }
    for (int i = 0; i < temp_a.size(); i++)
    {
        if (find(temp_b.begin(), temp_b.end(), temp_a[i]) != temp_b.end())
        {
            result += (temp_a[i]);
        }
    }
    return result;
}