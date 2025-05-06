#include <bits/stdc++.h>

#define ll long long
#define MAX 1005

using namespace std;

ll bit[MAX][MAX];

void updatePoint(int x, int y, ll val = 1) {
    for (int i = x; i < MAX; i += (i & -i)) 
        for (int j = y; j < MAX; j += (j & -j)) 
            bit[i][j] += val;
}

ll getSum(int x, int y) {
    ll sum = 0;
    for (int i = x; i > 0; i -= (i & -i)) 
        for (int j = y; j > 0; j -= (j & -j)) 
            sum += bit[i][j];
    return sum;
}

ll getQuery(int x1, int y1, int x2, int y2) {
    ll cntPoints = getSum(x2, y2) - getSum(x1 - 1, y2) - getSum(x2, y1 - 1) + getSum(x1 - 1, y1 - 1);
    ll res = cntPoints * (cntPoints - 1) * (cntPoints - 2) / 6;
    return res;
}

void solve(){
    int q;
    cin >> q;

    while(q--){
        int type;
        cin >> type;

        if(type == 1) {
            int x, y;
            cin >> x >> y;
            updatePoint(x, y);
        } 
        else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << getQuery(x1, y1, x2, y2) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}