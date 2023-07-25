#include <bits/stdc++.h>
using namespace std;
int main()
{
    //NOTE: we need a cost adjacency matrix representing the edges.
    int stages = 4, MIN;
    int n = 8; //8 vertices
    vector<int> cost(n + 1), d(n + 1), path(stages + 1);
    //Adjacency matrix.
    //size is 9 x 9 because vertices start from 1 and index start from 0.
    int c[9][9] =  {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 2, 1, 3, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 2, 3, 0, 0},
                    {0, 0, 0, 0, 0, 6, 7, 0, 0},
                    {0, 0, 0, 0, 0, 6, 8, 9, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 6},
                    {0, 0, 0, 0, 0, 0, 0, 0, 4},
                    {0, 0, 0, 0, 0, 0, 0, 0, 5},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    cost[n] = 0;
    for (int i = n - 1; i >= 1; i--) {
        MIN = INT_MAX;
        for (int k = i + 1; k <= n; k++) {
            if (c[i][k] != 0 && c[i][i] + cost[k] < MIN) {
                MIN = c[i][k] + cost[k];
                d[i] = k;
            }
        }
        cost[i] = MIN;
    }
    path[0] = -1; //since we start from index 1-1.
    path[1] = 1, path[stages] = n;
    for (int i = 2; i < stages; i++) {
        path[i] = d[path[i - 1]];
    }
    cout << "Final path for the multigraph is: " << '\n';
    for (int i = 1; i <= stages; i++) {
        cout << path[i] << ' ';
    }
    cout << '\n';
    return 0;
}