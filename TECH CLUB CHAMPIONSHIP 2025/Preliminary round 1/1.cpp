#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

string s;
int dp[20][2][10];

int cnt(int pos, bool lower, int first_digit)
{
    if (pos == s.size())
        return first_digit;

    if (dp[pos][lower][first_digit] != -1)
    {
        return dp[pos][lower][first_digit];
    }

    int res = 0;
    int limit = lower ? (s[pos] - '0') : 9;

    for (int d = 0; d <= limit; ++d)
    {
        bool new_lower = lower && (d == limit);
        int new_first = max(first_digit, d);
        res = (res + cnt(pos + 1, new_lower, new_first)) % MOD;
    }

    return dp[pos][lower][first_digit] = res;
}

int sum_first_digit(string x)
{
    s = x;
    memset(dp, -1, sizeof(dp));
    return cnt(0, 1, 0);
}

int sum_first_digit(long long x)
{
    return sum_first_digit(to_string(x));
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long L, R;
        cin >> L >> R;

        int ans = (sum_first_digit(R) - sum_first_digit(L - 1) + MOD) % MOD;
        cout << ans << "\n";
    }
    return 0;
}
