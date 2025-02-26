#include <bits/stdc++.h>

#define ll long long
#define mod 1000000007

using namespace std;

// vector<int> numbers;
// vector<int> dp(100'005, -1);

// void init(int limit = 100'000){
//     for(int i = 0; i < limit; ++i){
//         string tmp = to_string(i);
//         bool check = true;
//         for(char c : tmp)
//             if(c != '1' && c != '2' && c != '3'){
//                 check = false;
//                 break;
//             }

//         if(check) numbers.push_back(i);
//     }

//     dp[0] = 0;
//     for(int i = 1; i <= limit; i++){
//         dp[i] = 100000000;
//         for(int j = 0; j < numbers.size(); j++){
//             if(i - numbers[j] >= 0){
//                 dp[i] = min(dp[i], dp[i - numbers[j]] + 1);
//             }
//         }
//     }
// }

unordered_map<ll, int> mp;

int find(long long n){
    if(n == 0) return 0;
    if(mp.find(n) != mp.end()) return mp[n];
    //if(n <= 100'000) return dp[n];
    
    int m = find(n / 10), p = n % 10;

    if(1 <= p && p <= 3 && m <= 1) return mp[n] = 1;
    else if(2 <= p && p <= 6 && m <= 2) return mp[n] = 2;
    else if(3 <= p && p <= 9 && m <= 3) return mp[n] = 3;
    else if(4 <= p && p <= 9 && m <= 4) return mp[n] = 4;
    else if(0 <= p && p <= 2 && find(n / 10 - 1) <= 4) return mp[n] = 4;
    return mp[n] = 5;
}

void solve(){
    long long n;
    cin >> n;
    cout << find(n) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //init();

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    //cerr << "Process returned 0.\nExecution time: " << 0.001 * clock() << " s";
    return 0;
}