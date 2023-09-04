// https://codeforces.com/gym/317667/problem/G
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int n, m;
vector<pair<ll, ll>> edges[100005]; // pair<ll, ll> - {destination, weight}
ll dists[100005];
bool visited[100005];
void dijkstra(ll source) {
    for (int i = 0; i < n; i++) {
        dists[i] = 1e18; // infinity at the beginning
        visited[i] = false;
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dists[source] = 0;
    // visited[source] = true;
    pq.push({0, source}); // {cost, destination}
    while (!pq.empty()) {
        pair<ll, ll> current = pq.top();
        pq.pop();
        ll distance = current.first, target = current.second;

        if (visited[target]) continue;

        visited[target] = true;

        for (pair<ll, ll> node : edges[target]) {
            ll node_distance = distance + node.second;
            if (node_distance < dists[node.first]) {
                dists[node.first] = node_distance;
                pq.push({dists[node.first], node.first}); // {cost, destination}
            }
        }
    }
}
void test_case() {
    int k; cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        ll x, y, z; cin >> x >> y >> z; // x, y = vertex/nodes, z = cost/distance
        --x; --y;
        edges[x].push_back({y, z});
        edges[y].push_back({x, z});
    }
    for (int i = 0; i < n; i++) {
        edges[i].push_back({n, a[i]});
        edges[n].push_back({i, a[i]});
    }
    ++n;
    for (int i = 0; i < k; i++) {
        ll x; cin >> x;
        --x;
        dijkstra(x);
        for (int j = 0; j < n - 1; j++) {
            cout << dists[j] << ' ';
        }
        cout << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_case();
    return 0;
}
