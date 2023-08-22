// https://codeforces.com/gym/317667/problem/D
#include <bits/stdc++.h>
using namespace std;
vector<int64_t> edges[100005];
bool visited[100005];
bool color[100005];
bool possible = true;
void dfs(int node, bool c) {
    if (!visited[node]) {
        visited[node] = true;
        color[node] = c;
        for (auto i : edges[node]) {
            if (!visited[i]) {
                dfs(i, c ^ 1);
            }
            else {
                if (c == color[i]) {
                    possible = false;
                }
            }
        }
    }
}
void test_case() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    } 
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, false);
        }
    }

    if (possible) {
        int64_t cnt[2] = {0};
        for (int i = 0; i < n; i++) {
            cnt[color[i]]++;
        }
        
        cout << cnt[0] << '\n';
        for (int i = 0; i < n; i++) {
            if (color[i] == false) 
                cout << i + 1 << ' ';
        }
        cout << '\n';

        cout << cnt[1] << '\n';
        for (int i = 0; i < n; i++) {
            if (color[i] == true) {
                cout << i + 1 << ' ';
            }
        }
        cout << '\n';
    }
    else {
        cout << -1 << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_case();
    return 0;
}
