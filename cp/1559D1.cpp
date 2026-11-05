#include <bits/stdc++.h>

using namespace std;

int find(int i, int parent[]) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i], parent);
}

void union_sets(int x, int y, int parent[], int sz[]) {
    int rx = find(x, parent), ry = find(y, parent);
    if (rx != ry) {
        if (rx < ry) swap(rx, ry);
        parent[ry] = rx;
        sz[rx] += sz[ry];
    }
}

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    int parent1[n+1], parent2[n+1], size1[n+1], size2[n+1];

    for (int i = 1; i <= n; i++) {
        parent1[i] = i; parent2[i] = i;
        size1[i] = 1; size2[i] = 1;
    }

    for (int i = 1; i <= m1; i++) {
        int u, v;
        cin >> u >> v;
        if (find(u, parent1) == find(v, parent1)) continue;
        union_sets(u, v, parent1, size1);
    }

    for (int i = 1; i <= m2; i++) {
        int u, v;
        cin >> u >> v;
        if (find(u, parent2) == find(v, parent2)) continue;
        union_sets(u, v, parent2, size2);
    }

    vector<pair<int, int>> paths;
    paths.reserve(max(m1, m2));

    for (int i = 1; i <= n-1; i++) {
        for (int j = i+1; j <= n; j++) {
            if (!(find(i, parent1) == find(j, parent1)) && !(find(i, parent2) == find(j, parent2))) {
                paths.push_back({i, j});
                union_sets(i, j, parent1, size1);
                union_sets(i, j, parent2, size2);
            }
        }
    }

    cout << paths.size();
    if (paths.size() == 0) return;
    for (auto x : paths) {
        cout << "\n" << x.first << " " << x.second;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    while (t--) {
        solve();
    }
    return 0;
}
