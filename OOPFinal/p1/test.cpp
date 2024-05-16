#include<iostream>
 using namespace std;

 void f(int& x) {
     x += 1;
     cout << -1 << endl;
 }

 void f(int&& x) {
     int& y = x;             // (1)
     const int& z = y + 1;   // (2)
     cout << 0<< endl;
     f(y);                   // (3)
 }

 int main() {
     int a = 1;
     f(a);       // (4)
     cout << 4<< endl;
     f(1);       // (5)
     return 0;}
