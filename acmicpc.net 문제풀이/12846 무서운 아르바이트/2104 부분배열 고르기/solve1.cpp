// 이것도 히스토그램 변형문제!!!
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int N;
vector<ll> vA;
vector<ll> pSum;
void input()
{
    cin >> N;
    int n;
    vA.push_back(0);
    for (int i = 1; i <= N; i++)
    {
        cin >> n;
        vA.push_back(n);
    }
    pSum.push_back(0);
    for (int i = 1; i <= N; i++)
        pSum.push_back(pSum.back() + vA[i]);
}
ll getMxScore(int begin, int end)
{
    if (begin == end) return vA[begin] * vA[begin];
    int mid = (begin + end) / 2;
    ll res = max(getMxScore(begin, mid), getMxScore(mid + 1, end));
    ll minA = min(vA[mid], vA[mid + 1]);
    int tmp_l = mid, tmp_r = mid + 1;
    res = max(res, (pSum[mid + 1] - pSum[mid - 1]) * minA);
    while (tmp_l > begin || tmp_r < end)
    {
        if (tmp_r < end && (tmp_l == begin || vA[tmp_l - 1] < vA[tmp_r + 1]))
        {
            tmp_r++;
            minA = min(minA, vA[tmp_r]);
        }
        else
        {
            tmp_l--;
            minA = min(minA, vA[tmp_l]);
        }
        res = max(res, (pSum[tmp_r] - pSum[tmp_l - 1]) * minA);
    }
    return res;
}
void solve()
{
    input();
    cout << getMxScore(1, N);
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
