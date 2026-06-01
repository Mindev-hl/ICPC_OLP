#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fi first
#define se second

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    map<ll, int> mp;
    mp[0] = 1;
    ll sum = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        ll tmp = sum - x;
        if (mp.count(tmp))
        {
            count += mp[tmp];
        }
        mp[sum]++;
    }
    cout << count;
}