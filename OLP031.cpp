#include <bits/stdc++.h>

#define ll long long
#define MAXN 100005

using namespace std;

int n;
ll bit[MAXN];

void update(int u, int val) {
    for(int idx = u; idx <= n; idx += (idx & -idx)) 
        bit[idx] += val;
}

ll getSum(int u) {
    ll sum = 0;
    for(int idx = u; idx > 0; idx -= (idx & -idx)) 
        sum += bit[idx];
    return sum;
}

void solve(){
    cin >> n;
    ll arr[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        update(i, arr[i]);
    }
     
    int q;
    cin >> q;
    while(q--) {
        int type, x, y;
        cin >> type >> x >> y;
        if(type == 1) {
            arr[x] = y;
            update(x, arr[x]);
        } else {
            cout << getSum(y) - getSum(x - 1) << endl;
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