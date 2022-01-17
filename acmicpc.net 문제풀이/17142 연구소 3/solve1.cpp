// 우선 이 문제 및 연구소 시리즈를 통해서 알게 된 점
// 최단거리를 구해야하는데 여러 지점으로부터 동시에 출발하는 경우에는 큐를 이용해서 처리하자!
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N, M, min_time = INT_MAX;
int lab[50][50], lab_copied[50][50], isUsed[50][50], isVisited[50][50], isVirus[50][50];
const int d[4][2] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};
vector<pair<int, int>> v_virus;
void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> lab[i][j];
            if (lab[i][j] == 2)
            {
                v_virus.push_back({ i, j });
                lab[i][j] = 0;
                isVirus[i][j] = 1;
            }
            else if (lab[i][j] == 1)
                lab[i][j] = -1;
        }
}
bool isAllInfected()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (lab_copied[i][j] == 0 && !isVirus[i][j])
                return false;
    return true;
}
int getMinNum()
{
    int res = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (lab[i][j] == 0 && !isVirus[i][j])
                res = max(res, lab_copied[i][j]);
    return res;
}
void bfs()
{
    queue<pair<int, int>> q;
    for (int i = 0; i < v_virus.size(); i++)
        if (isUsed[v_virus[i].first][v_virus[i].second])
        {
            q.push({ v_virus[i].first, v_virus[i].second });
            lab_copied[v_virus[i].first][v_virus[i].second] = 0;
        }
    while (!q.empty())
    {
        int cur_y = q.front().first, cur_x = q.front().second;
        q.pop();
        for (int type = 0; type < 4; type++)
        {
            int next_y = cur_y + d[type][0], next_x = cur_x + d[type][1];
            if (0 <= next_x && next_x < N && 0 <= next_y && next_y < N && !isVisited[next_y][next_x] && lab_copied[next_y][next_x] != -1 && !isUsed[next_y][next_x])
            {
                lab_copied[next_y][next_x] = lab_copied[cur_y][cur_x] + 1;
                isVisited[next_y][next_x] = 1;
                q.push({ next_y, next_x });
            }
        }
    }
}
void findMinTime(int start_idx, int cur_virus)
{
    if (cur_virus == M)
    {
        copy(&lab[0][0], &lab[0][0] + 50 * 50, &lab_copied[0][0]);
        fill(&isVisited[0][0], &isVisited[0][0] + 50 * 50, 0);
        bfs();
        if (isAllInfected())
            min_time = min(min_time, getMinNum());
        return;
    }
    for (int i = start_idx; i < v_virus.size(); i++)
    {
        int cur_y = v_virus[i].first, cur_x = v_virus[i].second;
        if (lab[cur_y][cur_x] != 2)
        {
            lab[cur_y][cur_x] = 2;
            isUsed[cur_y][cur_x] = 1;
            findMinTime(i + 1, cur_virus + 1);
            lab[cur_y][cur_x] = 0;
            isUsed[cur_y][cur_x] = 0;
        }
    }
}
void solve()
{
    input();
    findMinTime(0, 0);
    if (min_time == INT_MAX)
        cout << -1 << endl;
    else
        cout << min_time << endl;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
