#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<long long> shares(n + 1, 0), debt(n + 1, 0), money(n + 1, 0);
    long long V = 0;

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int p;
            long long x;
            cin >> p >> x;
            money[p] = (money[p] + (shares[p] % MOD) * ((V - debt[p] + MOD) % MOD)) % MOD;
            debt[p] = V;
            shares[p] += x;
        }
        else if (type == 2)
        {
            long long v;
            cin >> v;
            V = (V + v % MOD) % MOD;
        }
        else
        {
            int p;
            cin >> p;
            long long ans = (money[p] + (shares[p] % MOD) * ((V - debt[p] + MOD) % MOD)) % MOD;
            cout << ans << "\n";
            money[p] = 0;
            debt[p] = V;
        }
    }
}
