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

    // Mảng phẳng lưu trữ mọi trạng thái dưới dạng {giá trị, số bước}
    vector<pair<ll, ll>> all_states;
    // Cấp phát trước bộ nhớ để tăng tốc (mỗi số max 70 bước)
    all_states.reserve(n * 70);

    for (int i = 0; i < n; i++)
    {
        ll x = a[i];
        int tmp = 0;
        vector<ll> visited; // Thay thế set bằng vector siêu nhẹ

        while (true)
        {
            // Kiểm tra xem x đã từng xuất hiện trong đường đi của chính nó chưa
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
                break; // Kẹt vào chu kỳ -> ngắt vòng lặp

            visited.push_back(x);
            all_states.push_back({x, tmp}); // Ghi nhận dấu chân

            // Áp dụng luật biến đổi
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

    // Sắp xếp lại toàn bộ trạng thái để gom các giá trị giống nhau lại gần nhau
    sort(all_states.begin(), all_states.end());

    ll min_ops = -1;
    int m = all_states.size();

    // Quét mảng phẳng để tìm đáp án
    for (int i = 0; i < m;)
    {
        int j = i;
        ll current_val = all_states[i].first;
        ll current_sum = 0;

        // Trượt con trỏ j để gộp tất cả các trạng thái có cùng giá trị
        while (j < m && all_states[j].first == current_val)
        {
            current_sum += all_states[j].second;
            j++;
        }

        int freq = j - i; // Tần suất xuất hiện của giá trị này

        // Nếu giá trị này được chạm tới bởi cả n số ban đầu
        if (freq == n)
        {
            if (min_ops == -1 || current_sum < min_ops)
            {
                min_ops = current_sum;
            }
        }

        i = j; // Nhảy cóc qua giá trị mới
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
    return 0;
}