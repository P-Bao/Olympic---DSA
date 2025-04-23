#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007

using namespace std;

ll dp[80][1 << 20];

void solve(){
    int n;
    cin >> n;
    string bits;
    cin >> bits;
    bits = '$' + bits;

    vector<int> pos1;
    for(int i = 1; i <= n; ++i)
        if(bits[i] == '1') pos1.push_back(i);

    //memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= n; ++i) dp[i][0] = 1;

    for(int i = 0; i <= n; ++i)
        for(int mask = 0; mask < (1 << 20); ++mask){
            if(dp[i][mask] == 0) continue;

            int val = 0;
            auto pos = upper_bound(pos1.begin(), pos1.end(), i);
            if(pos == pos1.end()) break;
            //cerr << *pos << endl;

            for(int nxt = *pos; nxt <= n; ++nxt) {
                val *= 2;
                val += bits[nxt] - '0';

                if(val > 20) break;
                if(val > 0){
                    dp[nxt][mask | (1 << (val - 1))] += dp[i][mask];
                    dp[nxt][mask | (1 << (val - 1))] %= MOD;
                }
            }
        }

    ll result = 0;
    for(int end = 1; end <= n; ++end)
        for(int m = 1; m <= 20; ++m){
            result += dp[end][(1 << m) - 1];
            result %= MOD;
        }
    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}