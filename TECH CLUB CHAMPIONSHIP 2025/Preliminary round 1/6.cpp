#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<ll> perfectSquares;
void init() {
    for (long long i = 0; i <= 10'000'000; ++i) {
        long long square = i * i;
        if (square <= 100'000'000'000'000LL) perfectSquares.push_back(square);
    }
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> freq(10, 0);
    for (int i = 0; i < n; ++i)
        freq[s[i] - '0']++;

    int cnt = 0;
    int i = 0;

    while(i < perfectSquares.size() && perfectSquares[i] < pow(10, n)) {
        ll cur = perfectSquares[i];
        vector<int> curFreq(10, 0);
        while (cur) {
            curFreq[cur % 10]++;
            cur /= 10;
        }

        if(freq[0] < curFreq[0]){
            i++;
            continue;
        }
        
        bool ok = true;
        for(int i = 1; i < 10; ++i)
            if(freq[i] != curFreq[i]) {
                ok = false;
                break;
            }
        
        if(ok) cnt++;
        i++;
    }    

    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    solve();
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}