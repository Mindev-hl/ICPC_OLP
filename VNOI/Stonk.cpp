#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fi first
#define se second
const ll MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;
    vector<ll> s(n + 1, 0), l(n + 1, 0);
    ll sumV = 0;
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll p, x;
            cin >> p >> x;
            s[p] += x;
            ll tmp = (x % MOD + MOD) % MOD;
            l[p] = (l[p] + tmp * sumV % MOD) % MOD;
        }
        else if (t == 2)
        {
            ll v;
            cin >> v;
            sumV = (sumV + v) % MOD;
        }
        else
        {
            ll b, p;
            cin >> p;
            b = ((s[p] % MOD) * sumV % MOD - l[p] + MOD) % MOD;
            cout << b << endl;
            l[p] = ((s[p] % MOD) * sumV) % MOD;
        }
    }
}