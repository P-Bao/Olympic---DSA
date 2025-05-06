#include <bits/stdc++.h>

#define ll long long
#define MAXN 100005

using namespace std;

int n;
ll bit[MAXN];

void updatePoint(int u, int val) {
    for(int idx = u; idx <= n; idx += (idx & -idx)) 
        bit[idx] += val;
}

void updateRange(int u, int v, int val) {
    updatePoint(u, val);
    updatePoint(v + 1, -val);
}

ll getSum(int u) {
    ll sum = 0;
    for(int idx = u; idx > 0; idx -= (idx & -idx)) 
        sum += bit[idx];
    return sum;
}

void solve(){
    cin >> n;
    ll arr[n + 1], diff[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        if(i > 1) diff[i] = arr[i] - arr[i - 1];
        else diff[i] = arr[i];

        updatePoint(i, diff[i]);
    }
     
    int q;
    cin >> q;
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int u, v, k;
            cin >> u >> v >> k;
            updateRange(u, v, k);
        } else {
            int u;
            cin >> u;
            cout << getSum(u) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}