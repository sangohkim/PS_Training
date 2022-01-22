// 파일 합치기 문제랑 비슷한 유형이라서 잘 풀수 있었다.
#include <bits/stdc++.h>
#define endl '\n'
#define ROW 0
#define COL 1
#define NLEN 501
#define INF INT_MAX
using namespace std;
int N, matSize[NLEN][2], cache[NLEN][NLEN];
void input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> matSize[i][ROW] >> matSize[i][COL];
}
int calCnt(int begin, int end)
{
    if (begin == end)
        return 0;
    if (end - begin + 1 == 2)
        return matSize[begin][ROW] * matSize[begin][COL] * matSize[end][COL];
    int& ret = cache[begin][end];
    if (ret != -1)
        return ret;
    ret = INF;
    for (int cut = begin; cut < end; cut++)
    {
        ret = min(ret, calCnt(begin, cut) + calCnt(cut + 1, end) + matSize[begin][ROW] * matSize[cut][COL] * matSize[end][COL]);
    }
    return ret;
}
void solve()
{
    input();
    fill(&cache[0][0], &cache[0][0] + NLEN * NLEN, -1);
    cout << calCnt(1, N) << endl;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
