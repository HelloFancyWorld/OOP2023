#include "altset.h"

Altset::Altset(const char *data, int len) : length(len)
{
    for (int i = 0; i < len; i++)
        gene.push_back(data[i]);
}

void Altset::inverse(int index)
{
    if(gene[length - index - 1] == '0')
        gene[length - index - 1] = '1';
    else
        gene[length - index - 1] = '0';
}

void Altset::append(int value)
{
    if(value == 0)
        gene.insert(gene.begin(), '0');
    else
        gene.insert(gene.begin(), '1');
    length++;
}

bool Altset::get(int index) const
{
    return (gene[length - index - 1] == '1');
}

bool Altset::empty() const
{
    return (length <= 0);
}

int Altset::count() const
{
    int result = 0;
    for (int i = 0; i < length; i++)
    {
        if (gene[i] == '1')
            result++;
    }
    return result;
}

Altset& Altset::operator=(const Altset &altset)
{
    if(this != &altset)
    {
        this->gene = altset.gene;
        this->length = altset.length;
    }
    return *this;
}
Altset& Altset::operator=(Altset &&altset) noexcept
{
    if(this != &altset)
    {
        this->gene = altset.gene;
        this->length = altset.length;
        vector<char>().swap(altset.gene);
        altset.length = 0;
    }
    return *this;
}