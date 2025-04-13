#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int n, m, s, t;
vector<tuple<int, ll, ll>> adj[100005];
ll dist[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s >> t;
    while (m--)
    {
        int u, v;
        ll w, k;
        cin >> u >> v >> w >> k;
        adj[u].push_back({v, w, k});
        adj[v].push_back({u, w, k});
    }

    fill(dist + 1, dist + n + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        auto [du, u] = pq.top();
        pq.pop();
        if (du > dist[u])
            continue;
        for (auto &[v, w, k] : adj[u])
        {
            ll wait = (du + k - 1) / k * k;
            ll dv = wait + w;
            if (dv < dist[v])
            {
                dist[v] = dv;
                pq.push({dv, v});
            }
        }
    }

    cout << (dist[t] == INF ? -1 : dist[t]);
}
