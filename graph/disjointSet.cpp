#include<bits/stdc++.h>
using namespace std;
class DisjointSet {
    private:
    vector<int> rank;
    vector<int> parent;

    public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUltimateParent(int node) {
        if (node == parent[node]) {
            return node;
        }

        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if (ulp_u == ulp_v) return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // if 3 and 7 are in same component or not
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
        cout << "In the same component" << '\n';
    }
    else {
        cout << "In different Component" << '\n';
    }
    ds.unionByRank(3, 7);


    // if 3 and 7 are in same component or not
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
        cout << "In the same component" << '\n';
    }
    else {
        cout << "In different Component" << '\n';
    }
    return 0;
}
