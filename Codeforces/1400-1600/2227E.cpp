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

    // M[i] lưu giá trị nhỏ nhất của các cột từ i+1 đến n
    vector<ll> M(n + 1, 0);
    ll current_min = 2e18; // Khởi tạo vô cực
    for (int i = n; i >= 1; i--)
    {
        M[i] = current_min;
        current_min = min(current_min, a[i]);
    }

    // Tính tổng số khối di chuyển ban đầu
    ll S = 0;
    for (int i = 1; i <= n; i++)
    {
        if (M[i] != 2e18 && a[i] > M[i])
        {
            S += a[i] - M[i];
        }
    }

    // Dùng Monotonic Stack tìm q[i]: vị trí gần nhất bên trái có a[q[i]] < a[i]
    vector<int> q(n + 1, 0);
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        // Loại bỏ các cột cao hơn hoặc bằng ra khỏi stack
        while (!st.empty() && a[st.top()] >= a[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            q[i] = 0; // Không có cột nào nhỏ hơn ở bên trái
        }
        else
        {
            q[i] = st.top();
        }
        st.push(i);
    }

    // Tìm lợi nhuận lớn nhất khi xóa 1 khối
    ll max_profit = -1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > 0)
        { // Chỉ xóa được nếu cột đó có ít nhất 1 khối
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

    // In ra kết quả
    cout << S + max_profit << "\n";
}

int main()
{
    // Tối ưu I/O cho C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t; // Đọc số lượng test case nếu có
    while (t--)
    {
        solve();
    }
    return 0;
}