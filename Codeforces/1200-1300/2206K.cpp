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
    ll count = 0;
    while (t--)
    {
        ll n;
        cin >> n;
        int a[n];
        string s;
        cin >> s;
        ll c0 = 0, c1 = 0, s5 = 0;
        for (auto x : s)
        {
            if (x == '0')
                c0++;
            else if (x == '1')
                c1++;
            if (x >= '0' && x <= '5')
                s5++;
        }
        ll l1 = n / 4, l2 = s5 / 2, l3 = (c1 / 2) + c0, l4 = (s5 + c0) / 3;
        ll MAXN = min({l1, l2, l3, l4});
        cout << MAXN << "\n";
    }
}