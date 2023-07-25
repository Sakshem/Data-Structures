//Creating a binary tree using class in c++
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int num; cin >> num;
    int count = 0;
    while (num > 0) {
        count += num & 1;
        num >>= 1;
    }
    cout << count << '\n';
    return 0;
}