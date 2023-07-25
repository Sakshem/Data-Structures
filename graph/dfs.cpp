#include <bits/stdc++.h>
using namespace std;
void DFS(int u, int A[][8], int n)
{
    // Initialize visit tracking array and stack
    int visited[8] {0};
    stack<int> stk;
    stk.emplace(u);
 
    // Visit start vertex u
    cout << u << ", " << flush;
    visited[u] = 1;  // Visited vertex u
 
    // Initial Adjacent vertex
    int v = 0;
 
    while (!stk.empty()){
        while (v < n){
            if (A[u][v] == 1 && visited[v] == 0){
                stk.push(u); // Suspend exploring current vertex u
                u = v;  // Update current vertex as the next adjacent vertex
 
                // Visit current vertex u
                cout << u << ", " << flush;
                visited[u] = 1;
                v = -1;  // Increment will make this 0
            }
            v++;
        }
        v = u;  // Can set v = 0 but setting v = u is better
        u = stk.top();  // Return to previous suspended vertex
        stk.pop();
    }
}
// Simpler and adds elements to stack from end
void dfs(int u, int A[][8], int n){
    int visited[8] {0};
    stack<int> stk;
    stk.emplace(u);
 
    while (!stk.empty()) {
        u = stk.top();
        stk.pop();
 
        if (visited[u] != 1) {
            cout << u << ", " << flush;
            visited[u] = 1;
 
            for (int v=n-1; v>=0; v--){
                if (A[u][v] == 1 && visited[v] == 0){
                    stk.emplace(v);
                }
            }
        }
    }
}
int vis[8];
void recursiveDFS(int u, int A[][8], int n) {
    if (vis[u] == 0) {
        cout << u << ", ";
        vis[u] = 1;
        for (int v = 1; v <= n; v++) {
            if (A[u][v] == 1 && vis[v] == 0) {
                recursiveDFS(v, A, n);
            }
        }
    }
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
 
    int u = 5;
    cout << "DFS Vertex: " << u << " -> " << flush;
    DFS(u, A, 8);
    cout << endl;
 
    cout << "dfs Vertex: " << u << " -> " << flush;
    dfs(u, A, 8);
    cout << endl;
    
    vis[8] = {0};
    cout << "dfs vertex: " << 1 << " -> ";
    recursiveDFS(1, A, 7);
    cout << '\n';
    return 0;
}
