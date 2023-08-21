// https://codeforces.com/gym/317667/problem/B
#include <bits/stdc++.h>
using namespace std;
vector<long long> edges[100005];
bool visited[100005];
long long dfs(int node, vector<long long> &cost) {
  long long mn = cost[node];
  visited[node] = true;
  for (auto i : edges[node]) {
    if (!visited[i]) {
      mn = min(mn, dfs(i, cost));
    }
  }
  return mn;
}
void test_case() {
  int n, m;
  cin >> n >> m;

  vector<long long> cost(n);
  for (auto &i : cost)
    cin >> i;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      ans += dfs(i, cost);
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
