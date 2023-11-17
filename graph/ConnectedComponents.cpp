// https://codeforces.com/problemset/problem/893/C
#include<bits/stdc++.h>
using namespace std;
vector<long long> edges[100005];
bool visited[100005];
long long dfs(int node, vector<long long>& cost) {
  long long mn = cost[node];
  visited[node] = true;
  for (auto i : edges[node]) {
    if (!visited[i]) {
      mn = min(mn, dfs(i, cost));
    }
    visited[i] = true;
  }
  return mn;
}
void test_case() {
  int n, m; cin >> n >> m;
  vector<long long> c(n);
  for (auto& i : c) cin >> i;
 
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    --u; --v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      ans += dfs(i, c);
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  test_case();
  return 0;
}
