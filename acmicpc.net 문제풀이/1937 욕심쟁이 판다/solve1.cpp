// dp, dfs를 이용하여 해결한 문제
// 처음에는 solve()의 반복문에서 panda()를 호출할 때마다 isVisited배열을 초기화해줬는데
// 이 부분때문에 시간초과가 난것 같다. 어차피 더 큰 값을 가진 원소만 방문하기 때문에 나를 호출한 그 전
// 좌표로는 돌아갈 수 없어서 결국 필요 없었고 그걸 지웠더니 시간안에 통과가 되었다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N;
int forest[500][500], cache[500][500];
const int d[4][2] = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}
};
void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> forest[i][j];
}
int panda(int y, int x)
{
    int& ret = cache[y][x];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int type = 0; type < 4; type++)
    {
        int ny = y + d[type][0], nx = x + d[type][1];
        if (0 <= ny && ny < N && 0 <= nx && nx < N && forest[ny][nx] > forest[y][x])
        {
            ret = max(ret, panda(ny, nx));
        }
    }
    return ret += 1;
}
void solve()
{
    input();
    int res = 0;
    fill(&cache[0][0], &cache[0][0] + 500 * 500, -1);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            res = max(res, panda(i, j));
        }
    cout << res << endl;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
