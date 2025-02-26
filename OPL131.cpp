#include <bits/stdc++.h>

using namespace std;

string to_string(__int128 num) {
    if (num == 0) return "0";
    string result;
    while (num > 0) {
        result.push_back('0' + num % 10);
        num /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

ostream& operator<<(ostream &os, __int128 num) {
    string s = to_string(num);
    if(s.size() > 10)
        os << s.substr(0, 5) + "..." + s.substr(s.size() - 5, 5);
    else
        os << s;
    return os;
}

int n, k;
__int128 dp[105][105][105];                                 

__int128 Count(int len, int openBrackets, int degree){
    if(len >= n){
        if(openBrackets == 0 && degree == k) return 1;
        return 0;
    }

    if(dp[len][openBrackets][degree] != -1) return dp[len][openBrackets][degree];
    
    __int128 cur = 0;
    cur += Count(len + 1, openBrackets + 1, max(degree, openBrackets + 1));
    if(openBrackets > 0)
        cur += Count(len + 1, openBrackets - 1, max(degree, openBrackets - 1));
    
    return dp[len][openBrackets][degree] = cur;
}


void solve(){
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    cout << Count(0, 0, 0) << endl;
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
    //cerr << "Process returned 0.\nExecution time: " << 0.001 * clock() << " s";
    return 0;
}