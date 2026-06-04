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
        ll n, x;
        cin >> n >> x;
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        ll count = 0;
        for (int i = 1; i <= n; i++)
        {
            ll pos = -1;
            for (int j = v.size() - 1; j >= 0; j--)
            {
                if (x >= v[j] / i + (v[j] % i != 0))
                {
                    pos = j;
                    break;
                }
            }
            if (pos == -1)
                break;
            v.erase(v.begin() + pos);
            count++;
        }

        cout << count << endl;
    }
}