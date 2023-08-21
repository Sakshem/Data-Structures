#include <bits/stdc++.h>
using namespace std;
void BFS(int vertex, int A[][8], int n)
{
    queue<int> Q;
    vector<bool> visited (n, false);
    cout << vertex << ", " << flush;
    visited[vertex] = true;
    Q.emplace(vertex);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v = 1; v <= n; v++) {
            if (A[u][v] == 1 && visited[v] == false) {
                cout << v << ", " << flush;
                visited[v] = true;
                Q.emplace(v);
            }
        }
    }
    cout << endl;
}
int main()
{
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
    cout << "vertex: 1-> " << flush << '\n';
    BFS(1, A, 8);
    return 0;
}
