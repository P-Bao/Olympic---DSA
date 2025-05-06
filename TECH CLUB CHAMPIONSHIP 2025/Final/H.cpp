#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, k;
vector<int> adj[1000005];
ll weight[1000005];

int cntRegion;
ll mid;

ll dfs(int u, int par) {
    ll sum = weight[u];
    for (int v : adj[u]) 
        if (v != par) 
            sum += dfs(v, u);
    
    if (sum >= mid) {
        cntRegion++;
        return 0;
    }
    return sum;
}

bool check(ll val) {
    mid = val;
    cntRegion = 0;
    dfs(1, 0);

    return cntRegion >= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    ll totalSum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> weight[i];
        totalSum += weight[i];
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll l = 1, r = totalSum, ans = 1;
    while (l <= r) {
        ll m = (l + r) / 2;
        if (check(m)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    cout << ans;
}