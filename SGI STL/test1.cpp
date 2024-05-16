#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int x, int y) // 自定义排序函数
{
    return x % 10 > y % 10;
}

int main()
{
    int num[10] = {6, 5, 9, 1, 2, 8, 7, 3, 4, 0};
    sort(num, num + 10, greater<int>());
    for (int i = 0; i < 10; i++)
    {
        cout << num[i] << " ";
    } // 输出结果:9 8 7 6 5 4 3 2 1 0
    cout << endl;
    int num2[10] = {65, 59, 96, 13, 21, 80, 72, 33, 44, 99};
    sort(num2, num2 + 10, cmp);
    for (int i = 0; i < 10; i++)
    {
        cout << num2[i] << " ";
    } // 输出结果：59 99 96 65 44 13 33 72 21 80
    return 0;
}
