#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define BLOCK_SIZE 350

struct Query {
    int l, r, idx;
    bool operator<(const Query& other) const {
        int blockA = l / BLOCK_SIZE, blockB = other.l / BLOCK_SIZE;
        if (blockA != blockB) return blockA < blockB;
        return (blockA & 1) ? (r < other.r) : (r > other.r);
    }
};

vector<int> arr;
vector<ll> res;
vector<Query> queries;
ll cntPair = 0;
int cnt[1000005] = {0};

void add(int val) {
    cntPair -= cnt[val] >> 1;
    cnt[val]++;
    cntPair += cnt[val] >> 1;
    
}

void remove(int val) {
    cntPair -= cnt[val] >> 1;
    cnt[val]--;
    cntPair += cnt[val] >> 1;
}

void processQueries() {
    sort(queries.begin(), queries.end());
    int l = 1, r = 0;
    for (auto& q : queries) {
        while (r < q.r) add(arr[++r]);
        while (r > q.r) remove(arr[r--]);
        while (l < q.l) remove(arr[l++]);
        while (l > q.l) add(arr[--l]);
        res[q.idx] = cntPair;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    arr.resize(n + 1);
    for (int i = 1; i <= n; ++i) cin >> arr[i];

    int m;
    cin >> m;
    queries.resize(m);
    res.resize(m);
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        queries[i] = {l, r, i};
    }

    processQueries();

    for (int i = 0; i < m; ++i) cout << res[i] << endl;

    return 0;
}