#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> q;
    q.push(10);
    cout << "q.front(): " << q.front() << '\n';
    cout << "q.rear(): " << q.back() << '\n';
    return 0;
}