#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fi first
#define se second

const ll MAXN = 32000;
const ll MAXM = 1e9;

bool a[MAXN + 1];

void sangso()
{

    fill(a, a + MAXN + 1, true);
    a[0] = a[1] = false;
    for (int i = 2; i * i <= MAXN; i++)
    {

        if (a[i])
        {
            for (int j = i * i; j <= MAXN; j += i)
            {
                a[j] = false;
            }
        }
    }
}

int main()
{
    if (fopen("SDB.INP", "r"))
    {
        freopen("SDB.INP", "r", stdin);
        freopen("SDB.OUT", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sangso();

    vector<ll> v;
    ll n;
    cin >> n;
    for (int i = 2; i <= MAXN; i++)
    {
        ll tmp;
        if (a[i])
        {
            v.push_back(1ll * i * i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        auto it = lower_bound(v.begin(), v.end(), x);
        cout << *it << "\n";
    }
}