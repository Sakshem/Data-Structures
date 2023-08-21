// https://codeforces.com/gym/317667/problem/C
#include <bits/stdc++.h>
using namespace std;
vector<int64_t> edges[500005];
bool visited[500005];
void bfs(int node, vector<int64_t> &component) {
  queue<int64_t> q;
  q.push(node);
  while (!q.empty()) {
    node = q.front();
    q.pop();
    if (visited[node])
      continue;

    visited[node] = true;
    component.push_back(node);
    for (auto i : edges[node]) {
      if (!visited[i]) {
        q.push(i);
      }
    }
  }
}
void dfs(int node, vector<int64_t> &component) {}
void test_case() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    vector<int64_t> v(k);
    for (auto &x : v) {
      cin >> x;
      x--;
    }
    for (int j = 0; j < k - 1; j++) {
      edges[v[j]].push_back(v[j + 1]);
      edges[v[j + 1]].push_back(v[j]);
    }
  }

  vector<int64_t> ans(n);
  for (int i = 0; i < n; i++) {
    vector<int64_t> component;
    if (!visited[i]) {
      bfs(i, component);
      for (auto x : component) {
        ans[x] = component.size();
      }
    }
  }

  for (auto i : ans)
    cout << i << ' ';
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  test_case();
  return 0;
}
