#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
vector<vector<tuple<int, ll, ll>>> graph;

int Dijkstra(int start, int end){
    vector<ll> time(n + 1, LLONG_MAX);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    pq.push({0, start});
    time[start] = 0;

    while(!pq.empty()){
        auto [curTime, u] = pq.top();
        pq.pop();

        if(curTime > time[u]) continue;

        for(auto &[dest, cost, k] : graph[u]){
            ll waitTime = (curTime % k == 0) ? 0 : (k - (curTime % k)),
               arrivalTime = curTime + cost + waitTime;

            if(arrivalTime < time[dest]){
                time[dest] = arrivalTime;
                pq.push({arrivalTime, dest});
            }
        }
    }

    return (time[end] == INT_MAX) ? -1 : time[end];
}

void solve(){
    int m, start, end;
    cin >> n >> m >> start >> end;

    graph.assign(n + 1, vector<tuple<int, ll, ll>>());
    for(int i = 0; i < m; i++){
        int u, v, c, k;
        cin >> u >> v >> c >> k;
        graph[u].emplace_back(v, c, k);
        graph[v].emplace_back(u, c, k);
    }

    cout << Dijkstra(start, end);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    solve();

    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}