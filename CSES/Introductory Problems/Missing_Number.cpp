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
    vector<ll> v(n);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    ll tmp = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == i)
        {
            tmp = i + 1;
        }
    }
    cout << tmp;
}