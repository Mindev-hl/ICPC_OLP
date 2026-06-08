#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<ll> M(n + 1, 0);
    ll current_min = 2e18;
    for (int i = n; i >= 1; i--)
    {
        M[i] = current_min;
        current_min = min(current_min, a[i]);
    }

    ll S = 0;
    for (int i = 1; i <= n; i++)
    {
        if (M[i] != 2e18 && a[i] > M[i])
        {
            S += a[i] - M[i];
        }
    }

    vector<int> q(n + 1, 0);
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && a[st.top()] >= a[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            q[i] = 0;
        }
        else
        {
            q[i] = st.top();
        }
        st.push(i);
    }

    ll max_profit = -1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > 0)
        {
            if (a[i] <= M[i])
            {
                ll profit = i - q[i] - 1;
                max_profit = max(max_profit, profit);
            }
            else
            {
                max_profit = max(max_profit, -1LL);
            }
        }
    }

    cout << S + max_profit << "\n";
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}