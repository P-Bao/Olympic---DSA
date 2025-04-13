#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<int> p = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,
    37, 41, 43, 47, 53, 59, 61, 67, 71};

ll n, r;

void bt(int i, ll x, ll d, int lim)
{
    if (x > n)
        return;
    r = max(r, d);
    if (i >= (int)p.size())
        return;

    ll y = x;
    for (int e = 1; e <= lim; ++e)
    {
        if (y > n / p[i])
            break;
        y *= p[i];
        bt(i + 1, y, d * (e + 1), e);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        r = 0;
        bt(0, 1, 1, 64);
        cout << r << '\n';
    }
    return 0;
}
