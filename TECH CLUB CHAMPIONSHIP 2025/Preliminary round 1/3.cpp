#include <bits/stdc++.h>

using namespace std;

void solve(){
    string num;
    cin >> num;
    
    int total = 0, freqMod[3] = {0};
    for(char c : num) {
        freqMod[(c - '0') % 3]++;
        total += (c - '0');
    }

    if(total % 3 == 0) cout << 0 << endl;
    else if(total % 3 == 1){
        if(freqMod[1] > 0 && num.size() > 1)
            cout << 1 << endl;
        else if(freqMod[2] > 1 && num.size() > 2)
            cout << 2 << endl;
        else 
            cout << -1 << endl;
    }
    else {
        if(freqMod[2] > 0 && num.size() > 1) 
            cout << 1 << endl;
        else if(freqMod[1] > 1 && num.size() > 2)
            cout << 2 << endl;
        else 
            cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    
    return 0;
}