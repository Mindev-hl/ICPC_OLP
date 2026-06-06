#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Cấu trúc lưu trữ thao tác vẽ
struct Operation
{
    int type;  // 0: Hàng, 1: Cột
    int index; // Vị trí (1-based)
    int color; // Màu
};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> r_colors(n);
    vector<vector<int>> c_colors(m);

    // Nhập dữ liệu và gom nhóm màu sắc
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] != 0)
            {
                r_colors[i].push_back(a[i][j]);
                c_colors[j].push_back(a[i][j]);
            }
        }
    }

    vector<int> row_distinct(n, 0), col_distinct(m, 0);
    vector<vector<int>> row_cnt(n), col_cnt(m);
    vector<bool> row_peeled(n, false), col_peeled(m, false);

    // Tiền xử lý hàng: Nén mảng màu và chuẩn bị mảng đếm tần suất
    for (int i = 0; i < n; i++)
    {
        sort(r_colors[i].begin(), r_colors[i].end());
        r_colors[i].erase(unique(r_colors[i].begin(), r_colors[i].end()), r_colors[i].end());
        row_distinct[i] = r_colors[i].size();
        row_cnt[i].assign(r_colors[i].size(), 0);
    }

    // Tiền xử lý cột
    for (int j = 0; j < m; j++)
    {
        sort(c_colors[j].begin(), c_colors[j].end());
        c_colors[j].erase(unique(c_colors[j].begin(), c_colors[j].end()), c_colors[j].end());
        col_distinct[j] = c_colors[j].size();
        col_cnt[j].assign(c_colors[j].size(), 0);
    }

    // Đếm tần suất xuất hiện ban đầu
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != 0)
            {
                int id_r = lower_bound(r_colors[i].begin(), r_colors[i].end(), a[i][j]) - r_colors[i].begin();
                row_cnt[i][id_r]++;

                int id_c = lower_bound(c_colors[j].begin(), c_colors[j].end(), a[i][j]) - c_colors[j].begin();
                col_cnt[j][id_c]++;
            }
        }
    }

    queue<pair<int, int>> q; // {loại, vị trí}

    // Đẩy các nét vẽ cuối cùng vào hàng đợi
    for (int i = 0; i < n; i++)
    {
        if (row_distinct[i] == 1)
            q.push({0, i});
    }
    for (int j = 0; j < m; j++)
    {
        if (col_distinct[j] == 1)
            q.push({1, j});
    }

    vector<Operation> ans;

    // Thuật toán BFS Tẩy màu ngược chiều
    while (!q.empty())
    {
        auto [type, idx] = q.front();
        q.pop();

        if (type == 0)
        { // Xử lý Hàng
            if (row_peeled[idx] || row_distinct[idx] != 1)
                continue;
            row_peeled[idx] = true;

            int C = -1;
            for (int i = 0; i < r_colors[idx].size(); i++)
            {
                if (row_cnt[idx][i] > 0)
                {
                    C = r_colors[idx][i];
                    break;
                }
            }

            if (C != -1)
            {
                ans.push_back({0, idx + 1, C});
                // Tẩy màu và cập nhật cho các cột tương ứng
                for (int j = 0; j < m; j++)
                {
                    if (a[idx][j] != 0)
                    {
                        int val = a[idx][j];
                        a[idx][j] = 0;

                        int id_c = lower_bound(c_colors[j].begin(), c_colors[j].end(), val) - c_colors[j].begin();
                        col_cnt[j][id_c]--;
                        if (col_cnt[j][id_c] == 0)
                        {
                            col_distinct[j]--;
                            if (col_distinct[j] == 1 && !col_peeled[j])
                            {
                                q.push({1, j});
                            }
                        }
                    }
                }
            }
        }
        else
        { // Xử lý Cột
            if (col_peeled[idx] || col_distinct[idx] != 1)
                continue;
            col_peeled[idx] = true;

            int C = -1;
            for (int i = 0; i < c_colors[idx].size(); i++)
            {
                if (col_cnt[idx][i] > 0)
                {
                    C = c_colors[idx][i];
                    break;
                }
            }

            if (C != -1)
            {
                ans.push_back({1, idx + 1, C});
                // Tẩy màu và cập nhật cho các hàng tương ứng
                for (int i = 0; i < n; i++)
                {
                    if (a[i][idx] != 0)
                    {
                        int val = a[i][idx];
                        a[i][idx] = 0;

                        int id_r = lower_bound(r_colors[i].begin(), r_colors[i].end(), val) - r_colors[i].begin();
                        row_cnt[i][id_r]--;
                        if (row_cnt[i][id_r] == 0)
                        {
                            row_distinct[i]--;
                            if (row_distinct[i] == 1 && !row_peeled[i])
                            {
                                q.push({0, i});
                            }
                        }
                    }
                }
            }
        }
    }

    // Kiểm tra tính hợp lệ
    bool possible = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != 0)
            {
                possible = false;
                break;
            }
        }
        if (!possible)
            break;
    }

    // In kết quả
    if (!possible)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        cout << ans.size() << "\n";
        for (int i = (int)ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i].type << " " << ans[i].index << " " << ans[i].color << "\n";
        }
    }
}

int main()
{
    // Tối ưu hóa I/O để chống TLE
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