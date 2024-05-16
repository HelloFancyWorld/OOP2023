#include <vector>
#include <functional>
using namespace std;


template<typename T>
class Compare {
public:
    vector<function<bool(T, T)>> comparators;
    Compare(initializer_list<function<bool(T, T)>> init_list) : comparators(init_list) {}
    Compare(vector<function<bool(T, T)>> init_list) : comparators(init_list) {}
    bool operator()(T a, T b) {
        for (auto &comp : comparators) {
            if (comp(a, b)) return true;
            if (comp(b, a)) return false;
        }
        return false;
    }
};
