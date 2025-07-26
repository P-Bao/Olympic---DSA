#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007
#define INF 1000000000

using namespace std;

string n;
ll dp[20][8][2], cnt68[20][8][2];

void solve(){
    cin >> n;
    
    memset(dp, 0, sizeof(dp));
    memset(cnt68, 0, sizeof(cnt68));
    dp[0][0][1] = 1; // Starting with the first digit, 0 count of 0s, and tight bound
    int len = n.size();

    for(int pos = 0; pos < len; ++pos)
        for(int mod = 0; mod < 8; ++mod) 
            for(int tight = 0; tight < 2; ++tight) {
                if(dp[pos][mod][tight] == 0) continue;

                int limit = tight ? (n[pos] - '0') : 9;
                for(int digit = 0; digit <= limit; ++digit) {
                    int newMod = (mod * 10 + digit) % 8;
                    int newTight = tight && (digit == limit);
        
                    dp[pos + 1][newMod][newTight] += dp[pos][mod][tight];
                    cnt68[pos + 1][newMod][newTight] += cnt68[pos][mod][tight] + (digit == 6 || digit == 8) * dp[pos][mod][tight];
                    }
                }

    cout << cnt68[len][0][0] + cnt68[len][0][1] << endl; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}