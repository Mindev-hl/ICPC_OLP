#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;

    for (long long a = 2; a * a * a <= n; a++)
    {
        if (n % a != 0)
            continue;
        long long rem = n / a;

        for (long long b = a + 1; b * b <= rem; b++)
        {
            if (rem % b != 0)
                continue;
            long long c = rem / b;

            if (c > b)
            {
                cout << "YES\n";
                cout << a << " " << b << " " << c << "\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}