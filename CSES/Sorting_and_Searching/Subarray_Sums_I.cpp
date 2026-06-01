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

    ll l = 0, sum = 0, count = 0;
    for (int r = 0; r < n; r++)
    {
        sum += a[r];
        while (sum > x && l <= r)
        {
            sum -= a[l];
            l++;
        }
        if (sum == x)
        {
            count++;
        }
    }
    cout << count;
}