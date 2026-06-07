#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    // 1. Tạo Tam giác C3 trên 3 đỉnh {1, 2, 3}
    int edges[3][2] = {{1, 2}, {2, 3}, {3, 1}};
    for (int i = 0; i < 3; i++)
    {
        cout << "? " << edges[i][0] << " " << edges[i][1] << endl;
        int resp;
        cin >> resp;
        if (resp == -1)
            exit(0); // Bắt lỗi hệ thống
        if (resp == 1)
        {
            cout << "! " << edges[i][0] << endl;
            return;
        }
    }

    // 2. Tạo n-2 cặp cạnh rời rạc K2 trên các đỉnh từ 4 đến 2n-1
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

    // 3. Nếu tất cả đều trả về 0, đỉnh cô lập cuối cùng (2n) chắc chắn là số 0
    cout << "! " << 2 * n << endl;
}

int main()
{
    // Tối ưu I/O không cần thiết với bài Interactive,
    // quan trọng nhất là flush output (endl)
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