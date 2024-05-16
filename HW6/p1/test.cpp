#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
class IntNum {
public:
    int value;
    IntNum(int _value) : value(_value) {}
    bool operator<(const IntNum& b) const { 
        return value > b.value;
    };
};

void my_sort(vector<int>& arr) {
    vector<IntNum> nums;
    for (int i : arr) nums.push_back(IntNum(i));
    sort(nums.begin(), nums.end());
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = nums[i].value;
    }
}




int main() {
    vector<int> m;
    m.push_back(3);
    m.push_back(2);
    m.push_back(4);
    m.push_back(5);
    m.push_back(1);

    my_sort(m);
    for (int i = 0; i < 5; i++)
        cout << m[i];
        return 0;
}
