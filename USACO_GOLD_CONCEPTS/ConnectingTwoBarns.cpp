
#include <bits/stdc++.h>
using namespace std;

int p[100005];
long long cost1[100005];
long long costN[100005];
vector<int> comp1;
vector<int> compN;

int find_set(int v) {
    if (v == p[v]) return v;
    return p[v] = find_set(p[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) p[b] = a;
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        p[i] = i;
        cost1[i] = 1e18;
        costN[i] = 1e18;
    }
    comp1.clear();
    compN.clear();

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        union_sets(u, v);
    }

    int root1 = find_set(1);
    int rootN = find_set(n);

    for (int i = 1; i <= n; i++) {
        if (find_set(i) == root1) comp1.push_back(i);
        if (find_set(i) == rootN) compN.push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        int root = find_set(i);

        auto it1 = lower_bound(comp1.begin(), comp1.end(), i);
        if (it1 != comp1.end()) {
            long long d = (long long)(*it1 - i) * (*it1 - i);
            if (d < cost1[root]) cost1[root] = d;
        }
        if (it1 != comp1.begin()) {
            it1--;
            long long d = (long long)(i - *it1) * (i - *it1);
            if (d < cost1[root]) cost1[root] = d;
        }

        auto itN = lower_bound(compN.begin(), compN.end(), i);
        if (itN != compN.end()) {
            long long d = (long long)(*itN - i) * (*itN - i);
            if (d < costN[root]) costN[root] = d;
        }
        if (itN != compN.begin()) {
            itN--;
            long long d = (long long)(i - *itN) * (i - *itN);
            if (d < costN[root]) costN[root] = d;
        }
    }

    long long ans = 1e18;
    for (int i = 1; i <= n; i++) {
        if (p[i] == i) {
            if (cost1[i] + costN[i] < ans) {
                ans = cost1[i] + costN[i];
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
