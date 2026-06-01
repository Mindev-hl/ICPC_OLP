#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fi first
#define se second

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll count = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
        {
            count += 1;
        }
    }
    cout << count;
}