#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    int edges[3][2] = {{1, 2}, {2, 3}, {3, 1}};
    for (int i = 0; i < 3; i++)
    {
        cout << "? " << edges[i][0] << " " << edges[i][1] << endl;
        int resp;
        cin >> resp;
        if (resp == -1)
            exit(0);
        if (resp == 1)
        {
            cout << "! " << edges[i][0] << endl;
            return;
        }
    }

    int u = 4;
    for (int k = 0; k < n - 2; k++)
    {
        cout << "? " << u << " " << u + 1 << endl;
        int resp;
        cin >> resp;
        if (resp == -1)
            exit(0);
        if (resp == 1)
        {
            cout << "! " << u << endl;
            return;
        }
        u += 2;
    }

    cout << "! " << 2 * n << endl;
}

int main()
{
    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
}