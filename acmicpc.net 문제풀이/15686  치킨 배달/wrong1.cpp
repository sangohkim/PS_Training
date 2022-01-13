// 나는 문제를 보자 마자 조합은 완전탐색으로, 치킨 거리 계산은 최단거리문제와 같으니 BFS를 쓰면 되겠다고 생각했다
// 완전탐색까지는 괜찮았는데 bfs가 문제였다. bfs때문에 계속 메모리 초과로 풀지 못하고 있었다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N, M, arrNoChick[50][50], mn_dist = INT_MAX;
const int d[4][2] = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}
};
vector<pair<int, int>> chicken;
int cal_bfs(int y, int x)
{
    queue<pair<int, int>> q;
    q.push({ y, x });
    while (!q.empty())
    {
        int cy = q.front().first, cx = q.front().second;
        q.pop();
        if (arrNoChick[cy][cx] == 2)
        {
            return int(abs(y - cy) + abs(x - cx));
        }
        for (int i = 0; i < 4; i++)
        {
            int ny = cy + d[i][0], nx = cx + d[i][1];
            q.push({ ny, nx });
        }
    }
}
void getMinDist(int start_idx, int cntChick)
{
    if (cntChick == M)
    {
        int res = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                if (arrNoChick[i][j] == 1)
                {
                    res += cal_bfs(i, j);
                }
            }
        mn_dist = min(mn_dist, res);
        return;
    }
    for (int i = start_idx; i < chicken.size(); i++)
    {
        int ny = chicken[i].first, nx = chicken[i].second;
        if (arrNoChick[ny][nx] != 2)
        {
            arrNoChick[ny][nx] = 2;
            getMinDist(i, cntChick + 1);
            arrNoChick[ny][nx] = 0;
        }
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> arrNoChick[i][j];
            if (arrNoChick[i][j] == 2)
            {
                chicken.push_back({ i, j });
                arrNoChick[i][j] = 0;
            }
        }
    getMinDist(0, 0);
    cout << mn_dist << endl;
}
