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

vector<__int128> catalan(101, 0);
void init(){
    catalan[0] = 1;
    for (int i = 1; i <= 100; i++){
        for (int j = 0; j < i; j++){
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }
}

void solve(){
    int n;
    cin >> n;

    n /= 2;
    cout << catalan[n] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    //cerr << "Process returned 0.\nExecution time: " << 0.001 * clock() << " s";
    return 0;
}