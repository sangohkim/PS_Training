// 히스토그램 변형문제
// 최대최소를 분할정복으로도 구할수 있음을 유의하자!
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N;
vector<long long> vpay;
void input()
{
    cin >> N;
    int n;
    vpay.push_back(0);
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        vpay.push_back(n);
    }
}
long long getMaxPay(int begin, int end)
{
    if (begin == end) return vpay[begin];
    int mid = (begin + end) / 2;
    long long res = max(getMaxPay(begin, mid), getMaxPay(mid + 1, end));
    int tmp_r = mid + 1, tmp_l = mid;
    long long height = min(vpay[tmp_r], vpay[tmp_l]);
    res = max(res, height * (tmp_r - tmp_l + 1));
    while (tmp_r < end || tmp_l > begin)
    {
        if (tmp_r < end && (tmp_l == begin || vpay[tmp_l - 1] < vpay[tmp_r + 1]))
        {
            tmp_r++;
            height = min(height, vpay[tmp_r]);
        }
        else
        {
            tmp_l--;
            height = min(height, vpay[tmp_l]);
        }
        res = max(res, height * (tmp_r - tmp_l + 1));
    }
    return res;
}
void solve()
{
    input();
    cout << getMaxPay(1, N) << endl;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
