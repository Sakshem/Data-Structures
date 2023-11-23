#include<bits/stdc++.h>
using namespace std;
int mxN = 1e5 + 1;
bool isCycle(int V, vector<int> adj[]) {
    vector<int> inDegree(V, 0);
    queue<int> q;
    int visited = 0;
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            inDegree[it]++;
        }
    }
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        visited++;
        for (auto i : adj[node]) {
            inDegree[i]--;
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
    }
    return visited != V;

}
void test_case() {
    int V = 4;
    vector<int> adj[mxN];
    for (int i = 0; i < V; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << isCycle(V, adj) << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_case();
    return 0;
}
