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
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll move = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[i - 1] > v[i])
        {
            move += (v[i - 1] - v[i]);
            v[i] = v[i - 1];
        }
    }
    cout << move;
}