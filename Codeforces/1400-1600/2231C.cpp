#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<pair<ll, ll>> all_states;
    all_states.reserve(n * 70);

    for (int i = 0; i < n; i++)
    {
        ll x = a[i];
        int tmp = 0;
        vector<ll> visited;

        while (true)
        {

            bool found = false;
            for (ll v : visited)
            {
                if (v == x)
                {
                    found = true;
                    break;
                }
            }
            if (found)
                break;

            visited.push_back(x);
            all_states.push_back({x, tmp});

            if (x % 2 == 0)
            {
                x /= 2;
            }
            else
            {
                x += 1;
            }
            tmp++;
        }
    }

    sort(all_states.begin(), all_states.end());

    ll min_ops = -1;
    int m = all_states.size();

    for (int i = 0; i < m;)
    {
        int j = i;
        ll current_val = all_states[i].first;
        ll current_sum = 0;

        while (j < m && all_states[j].first == current_val)
        {
            current_sum += all_states[j].second;
            j++;
        }

        int freq = j - i;

        if (freq == n)
        {
            if (min_ops == -1 || current_sum < min_ops)
            {
                min_ops = current_sum;
            }
        }

        i = j;
    }

    cout << min_ops << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
}