#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

#define MAXLEN 1000

class Altset
{
private:
    int length;
    //string gene;
    vector<char> gene;

public:
    Altset() : length(0) {}
    ~Altset() { }

    Altset(const char *data, int len);
    Altset &operator=(const Altset &altset);
    Altset &operator=(Altset &&altset) noexcept; 

    void inverse(int index);
    void append(int value);
    bool get(int index) const;
    bool empty() const;
    int count() const;
};
