#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <list>
#include <bitset>
#include <tuple>
#include <functional>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstring>
#include <cassert>
#include <fstream>
#include <chrono>
#include <random>

using namespace std;

#define int long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define rall(v) v.rbegin(), v.rend()
#define sz(x) (int)(x).size()
#define fi first
#define se second

void fast_io(bool use_file = false)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (use_file)
    {
        freopen("INPUT.in", "r", stdin);
        freopen("OUTPUT.out", "w", stdout);
    }
}

const int INF = 1e18;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

int binpow(int x, int y, int m = MOD)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = res * x % m;
        x = x * x % m;
        y >>= 1;
    }
    return res;
}

bool is_prime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

vector<int> sieve(int n)
{
    vector<int> is_prime(n + 1, 1), primes;
    is_prime[0] = is_prime[1] = 0;
    FOR(i, 2, n)
    {
        if (is_prime[i])
        {
            primes.pb(i);
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = 0;
        }
    }
    return primes;
}

#define debug(x) cerr << #x << " = " << (x) << endl
/*  0 số cách
    1 xuống
    2 phải
    3 chéo xuống */
const int N = 2005;
int dp[N][N][4] = {};
char a[N][N];
int check(int a)
{
    return a > 0 ? a : 0;
}
void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
            {
                dp[1][1][0] = dp[1][1][1] = dp[1][1][2] = dp[1][1][3] = 1;
                continue;
            }
            if (a[i][j] == '#')
                dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = dp[i][j][3] = 0;
            else
            {
                dp[i][j][0] = (dp[i - 1][j][1] + dp[i][j - 1][2] + dp[i - 1][j - 1][3]) % MOD;
                dp[i][j][1] = (dp[i - 1][j][1] + dp[i][j][0]) % MOD;
                dp[i][j][2] = (dp[i][j - 1][2] + dp[i][j][0]) % MOD;
                dp[i][j][3] = (dp[i - 1][j - 1][3] + dp[i][j][0]) % MOD;
            }
        }
    cout << dp[n][m][0] << '\n';
}

int32_t main()
{
    fast_io(false);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
