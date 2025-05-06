#include <bits/stdc++.h>

using namespace std;

double dp[105][105][105];

double cal(int a, int b, int c){
    //cerr << a << " " << b << " " << c << endl;

    if(a >= 100 || b >= 100 || c >= 100) return 0;
    
    if(dp[a][b][c] != 0) return dp[a][b][c];

    int total = a + b + c;
    double res = 1;
    res += 1.0 * a / total * cal(a + 1, b, c);
    res += 1.0 * b / total * cal(a, b + 1, c);
    res += 1.0 * c / total * cal(a, b, c + 1);

    //cerr << res << endl;
    
    return dp[a][b][c] = res;
}

void solve(){
    int a, b, c;
    cin >> a >> b >> c;

    cout << fixed << setprecision(6) << cal(a, b, c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}