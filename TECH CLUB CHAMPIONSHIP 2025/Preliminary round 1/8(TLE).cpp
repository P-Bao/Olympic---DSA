#include <bits/stdc++.h>

#define ll long long
#define mod 1000000007

using namespace std;

int n, k, a[200001];
vector<int> adj[200001];
vector<bool> visited(200001, false);

int dfs(int u, int target){
    visited[u] = true;
    int ans = 1;
    for(int v : adj[u])
        if(!visited[v] && a[v] >= target)
            ans += dfs(v, target);
    return ans;
}

// Tìm thấy một cách duyệt có độ cứng lớn hơn hoặc bằng target
bool check(int target){
    for(int i = 0; i < n; ++i){
        if(!visited[i] && a[i] >= target){
            fill(visited.begin(), visited.end(), false);
            int cnt = dfs(i, target);
            if(cnt >= k) return true;
        }
    }
    return false;
}

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int low = 1, high = 1000000, res = 1;
    while(low <= high){
        int mid = (low + high) >> 1;
        if(check(mid)){
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    } 

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}