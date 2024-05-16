#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Rack
{
    public:
        vector<int> goods;

        Rack() {}
        Rack(const Rack &);
        void operator+=(const int);
        void operator+=(const Rack&);
        friend ostream& operator<<(ostream&, const Rack&);
        int operator()(const int) const;
        void operator~();
        void operator--();
        void operator--(int);
        bool operator<(const Rack &);
        bool operator==(const Rack &);
        bool operator>(const Rack &);
};
Rack operator , (const Rack &a, const Rack &b);
Rack operator , (const Rack &a, const int b);
Rack operator , (const int b, const Rack &a);
Rack operator & (const Rack &, const Rack &);