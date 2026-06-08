#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
int spf[MAXN];

void sieve()
{
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;
    for (int i = 2; i * i < MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < MAXN; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n - 1);
    vector<int> primes;
    vector<int> composites;
    vector<int> orig_p;

    int p_count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i];
        if (spf[a[i]] == a[i])
        {
            primes.push_back(a[i]);
            p_count++;
        }
        else
        {
            composites.push_back(a[i]);
            orig_p.push_back(p_count);
        }
    }

    vector<int> pos_in_P(n + 1, 0);
    for (int i = 0; i < (int)primes.size(); i++)
    {
        pos_in_P[primes[i]] = i + 1;
    }

    long long total_swaps = 0;
    int max_R = 0;

    for (int i = 0; i < (int)composites.size(); i++)
    {
        int C = composites[i];
        int earliest_p_idx = 1e9;

        int temp = C;
        while (temp > 1)
        {
            int p = spf[temp];
            earliest_p_idx = min(earliest_p_idx, pos_in_P[p]);
            while (temp % p == 0)
                temp /= p;
        }

        max_R = max(max_R, earliest_p_idx);

        if (max_R > orig_p[i])
        {
            total_swaps += (max_R - orig_p[i]);
        }
    }

    cout << total_swaps << "\n";
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t;
    if (cin >> t)
    {
        while (t--)
            solve();
    }
    return 0;
}