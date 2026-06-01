#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fi first
#define se second

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    ll m = 1, tmp = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
        {
            tmp++;
        }
        else
        {
            m = max(m, tmp);
            tmp = 1;
        }
    }
    m = max(m, tmp);
    cout << m;
}