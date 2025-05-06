#include <bits/stdc++.h>

#define dii pair<double, pair<int, int>>
#define EPSILON 1e-6

using namespace std;

struct cmp {
    bool operator()(const dii &a, const dii &b) {
        return a.first - b.first > EPSILON;
    }
};

class DSU {
private:
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool union_sets(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];

            return true; 
        }

        return false;
    }
};

double distance(pair<int, int> a, pair<int, int> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

void solve(){
    int n;
    cin >> n;

    vector<pair<double, double>> points(n);
    for(int i = 0; i < n; ++i) 
        cin >> points[i].first >> points[i].second;

    priority_queue<dii, vector<dii>, cmp> pq;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            double dist = distance(points[i], points[j]);
            pq.push({dist, {i, j}});
        }
    }

    DSU dsu(n);
    double total_cost = 0.0;
    while(!pq.empty()) {
        auto [dist, edge] = pq.top();
        int u = edge.first, v = edge.second;
        pq.pop();

        if(dsu.union_sets(u, v))  total_cost += dist;
    }
     
    cout << fixed << setprecision(6) << total_cost << endl;
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