#include <iostream>
using namespace std;

template<typename T>
T add(T a, T b){
    T c = a + b;
    return c;
}

template<typename T>
T subtract(T a, T b){
    T c = a - b;
    return c;
}

int main(){
    int a = add(1.2, 1.3); // (1)
    int c = add(1, (int)add(1.2, 2.3)); // (3)
    int d = add<int>(1, 1.2); // (4)
    cout << d;
    return 0;
}
