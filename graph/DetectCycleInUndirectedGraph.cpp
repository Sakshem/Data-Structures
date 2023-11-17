#include<bits/stdc++.h>
using namespace std;
bool detectCycle(int node, int parent, vector<bool>& visited, vector<int> edges[]) {
    visited[node] = true;
    for (auto i : edges[node]) {
        if (!visited[i]) {
            if (detectCycle(i, node, visited, edges)) return true;
        }
        else if (i != parent) return true;
    }
    return false;
}
bool isCycleUsingDFS(int V, vector<int> edges[]) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (detectCycle(i, -1, visited, edges)) return true;
        }
    }
    return false;
}
bool isCycleUsingBFS(int V, vector<int> edges[]) {
    queue<pair<int, int>> q;
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            q.push({i, -1});
            while (!q.empty()) {
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();
                visited[node] = true;
                for (auto& it : edges[node]) {
                    if (!visited[it]) {
                        q.push({it, node});
                    }
                    else if (it != parent) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V = 5;
    vector <int> adj[V];

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(4);
    adj[4].push_back(1);

    adj[4].push_back(3);
    adj[3].push_back(4);

    adj[2].push_back(3);
    adj[3].push_back(2);
    
    if (isCycleUsingBFS(V, adj)) cout << "graph contains cycle" << '\n';
    else cout << "graph doesn't contain cycle" << '\n';
    return 0;
}
