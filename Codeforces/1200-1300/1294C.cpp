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
        ll n;
        cin >> n;
        for (int a = 2; a * a * a <= n; a++)
        {
            if (n % a != 0)
            {
                continue;
            }
            ll r = n / a;
            for (int b = a + 1; b * b <= r; b++)
            {
                if (n % b != 0)
                    continue;
                ll c = r / b;

                if (c > b)
                {
                    cout << "YES\n";
                    cout << a << " " << b << " " << c << endl;
                }
                else
                {
                    cout << "NO\n";
                }
            }
        }
    }
}