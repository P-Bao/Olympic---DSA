#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007
#define INF 1000000000
#define MAXSUM 9 * 15

using namespace std;

bool isPrime[MAXSUM + 5];
void sieve() {
    fill(isPrime, isPrime + MAXSUM + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAXSUM; i++) 
        if (isPrime[i]) 
            for (int j = i * i; j <= MAXSUM; j += i) 
                isPrime[j] = false;
}

ll dp[20][20][MAXSUM + 2][MAXSUM + 2]; 

void solve(){
    ll n;
    cin >> n;
    string strn = to_string(n);
    reverse(strn.begin(), strn.end());  // Đảo chuỗi để dễ xử lý từ chữ số thấp nhất

    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = 1;

    int len = strn.size();

    for(int pos = 0; pos < len; pos++) {
        for (int mem = 0; mem <= 9; mem++) {
            for (int sumx = 0; sumx <= MAXSUM; sumx++) {
                for(int sumy = 0; sumy <= MAXSUM; sumy++) {
                    if (dp[pos][mem][sumx][sumy] == 0) continue;

                    for(int dx = 0; dx <= 9; ++dx) {
                        for(int dy = 0; dy <= 9; ++dy) {
                            int total = dx + 2 * dy + mem;
                            if(total % 10 == (strn[pos] - '0')) {
                                int new_mem = total / 10;
                                dp[pos + 1][new_mem][sumx + dx][sumy + dy] += dp[pos][mem][sumx][sumy];
                            }
                        }
                    }
                }
            }
        }
    }

    ll res = 0;
    for(int sumx = 0; sumx <= MAXSUM; ++sumx) {
        for(int sumy = 0; sumy <= MAXSUM; ++sumy) {
            if(isPrime[sumx] && isPrime[sumy]) {
                res += dp[len][0][sumx][sumy];  // pos = len, mem = 0
            }
        }
    }

    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    sieve();
    solve();
    return 0;
}
