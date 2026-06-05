#include <iostream>

using namespace std;

void solve()
{
    long long l, r;
    int k;
    // SỬA LỖI: Đọc chính xác thứ tự l, r, k theo đúng format của đề
    cin >> l >> r >> k;

    bool can_cross = false;

    // Thử mọi hàng j có thể làm điểm xuất phát (từ 0 đến k-1)
    for (int j = 0; j < k; j++)
    {
        // Kiểm tra xem ô ở cột l, hàng j có trống không (bit thứ j có phải là 1)
        if ((l >> j) & 1)
        {
            // Tính cột xa nhất có thể vươn tới nếu chỉ đi trên hàng j
            unsigned long long max_reach = l | ((1ULL << j) - 1);

            // Nếu tầm với vượt qua hoặc chạm đến r, Saba an toàn
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
    // Tối ưu tốc độ I/O cho lập trình thi đấu
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