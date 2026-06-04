#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fi first
#define se second

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll sum = 0, max_m = 0;
    ll L = 0;
    for (int R = 0; R < n; R++)
    {
        sum += a[R];
        while (sum > t)
        {
            sum -= a[L];
            L++;
        }
        max_m = max(max_m, R - L + 1);
    }
    cout << max_m << "\n";
}