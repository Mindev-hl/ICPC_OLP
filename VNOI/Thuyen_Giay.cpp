#include <iostream>

using namespace std;

void solve()
{
    long long l, r;
    int k;
    cin >> l >> r >> k;

    bool can_cross = false;

    for (int j = 0; j < k; j++)
    {

        if ((l >> j) & 1)
        {

            unsigned long long max_reach = l | ((1ULL << j) - 1);

            if (max_reach >= (unsigned long long)r)
            {
                can_cross = true;
                break;
            }
        }
    }

    if (can_cross)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}