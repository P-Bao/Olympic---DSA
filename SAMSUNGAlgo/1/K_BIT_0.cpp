#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[33][33][2][2]; // dp[pos][cnt0][tight][started]
string nBin;
int k;

ll dpSolver(int pos, int cnt0, bool tight, bool started) {
    if (cnt0 > k) return 0;
    if (pos == nBin.size()) return cnt0 == k;

    if (dp[pos][cnt0][tight][started] != -1) 
        return dp[pos][cnt0][tight][started];

    ll res = 0;
    int limit = tight ? (nBin[pos] - '0') : 1;

    for (int d = 0; d <= limit; ++d) {
        bool newTight = tight && (d == limit);
        bool newStarted = started || (d != 0);
        int newCnt0 = cnt0 + (newStarted && d == 0);
        res += dpSolver(pos + 1, newCnt0, newTight, newStarted);
    }

    return dp[pos][cnt0][tight][started] = res;
}

void solve(){
    ll n;
    cin >> n >> k;

    if(n == 0) {
        if(k == 1)
            cout << 1 << '\n';
        else
            cout << 0 << '\n'; 
            
        return;
    }

    nBin = bitset<32>(n).to_string(); 
    nBin.erase(0, nBin.find_first_not_of('0')); 

    memset(dp, -1, sizeof(dp));
    ll res = dpSolver(0, 0, true, false);
    if(k == 1) res += 1;
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
