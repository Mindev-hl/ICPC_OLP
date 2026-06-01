#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fi first
#define se second

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        unordered_map<ll, ll> mp;
        for (int i = 1; i <= n; i++)
        {
            ll a;
            cin >> a;
            mp[a - i]++;
        }
        ll ans = 0;
        for (auto &[k, v] : mp)
        {
            ans += v * (v - 1) / 2;
        }
        cout << ans << endl;
    }
}