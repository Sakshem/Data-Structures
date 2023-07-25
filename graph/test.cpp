#include <bits/stdc++.h>
using namespace std;
int main()
{
/*    vector<int> edges[100];
//    vector of array
    int a;
    cin >> a;
    cout << a << ' ';
    edges[1].push_back(12);
    return 0;*/
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> nums = {2, 5, 1, 3, 4};
    for (int i = 0; i < nums.size(); i++) {
        pq.emplace(nums[i]);
    }
    while (!pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
    }
}
