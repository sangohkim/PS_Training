// 재귀호출할 때 매개변수에 i + 1을 해야 되는데 start + 1을 해서 계속 시간초과가 나던 
#include <bits/stdc++.h>
#define endl '\n'
#define WALL -1
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
using namespace std;
int N, M, office[8][8], cnt_blindspot = INT_MAX, isCCTV[8][8];
vector<pair<int, int>> v_cctv;

int cnt;

int BlindSpotCount()
{
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            if (!isCCTV[i][j] && office[i][j] != WALL && office[i][j] == 0)
                res++;
    }
    return res;
}
void change_office(int y, int x, int direction, int delta)
{
    if (direction == UP)
    {
        for (int i = y - 1; i >= 0; i--)
        {
            if (office[i][x] == WALL)
                break;
            office[i][x] += delta;
        }
    }
    else if (direction == DOWN)
    {
        for (int i = y + 1; i < N; i++)
        {
            if (office[i][x] == WALL)
                break;
            office[i][x] += delta;
        }
    }
    else if (direction == LEFT)
    {
        for (int j = x - 1; j >= 0; j--)
        {
            if (office[y][j] == WALL)
                break;
            office[y][j] += delta;
        }
    }
    else
    {
        for (int j = x + 1; j < M; j++)
        {
            if (office[y][j] == WALL)
                break;
            office[y][j] += delta;
        }
    }
}
void setCCTV(int start, int cntCCTV)
{
    if (cntCCTV == v_cctv.size())
    {
        cnt_blindspot = min(cnt_blindspot, BlindSpotCount());
        return;
    }
    for (int i = start; i < v_cctv.size(); i++)
    {
        int cy = v_cctv[i].first, cx = v_cctv[i].second;
        int type = isCCTV[cy][cx];
        if (type == 1)
        {
            for (int dir = UP; dir <= RIGHT; dir++)
            {
                change_office(cy, cx, dir, 1);
                setCCTV(i + 1, cntCCTV + 1);
                change_office(cy, cx, dir, -1);
            }
        }
        else if (type == 2)
        {
            change_office(cy, cx, UP, 1);
            change_office(cy, cx, DOWN, 1);
            setCCTV(i + 1, cntCCTV + 1);
            change_office(cy, cx, UP, -1);
            change_office(cy, cx, DOWN, -1);

            change_office(cy, cx, LEFT, 1);
            change_office(cy, cx, RIGHT, 1);
            setCCTV(i + 1, cntCCTV + 1);
            change_office(cy, cx, LEFT, -1);
            change_office(cy, cx, RIGHT, -1);
        }
        else if (type == 3)
        {
            change_office(cy, cx, UP, 1);
            change_office(cy, cx, RIGHT, 1);
            setCCTV(i + 1, cntCCTV + 1);
            change_office(cy, cx, UP, -1);
            change_office(cy, cx, RIGHT, -1);

            change_office(cy, cx, RIGHT, 1);
            change_office(cy, cx, DOWN, 1);
            setCCTV(i + 1, cntCCTV + 1);
            change_office(cy, cx, RIGHT, -1);
            change_office(cy, cx, DOWN, -1);

            change_office(cy, cx, LEFT, 1);
            change_office(cy, cx, DOWN, 1);
            setCCTV(i + 1, cntCCTV + 1);
            change_office(cy, cx, LEFT, -1);
            change_office(cy, cx, DOWN, -1);

            change_office(cy, cx, UP, 1);
            change_office(cy, cx, LEFT, 1);
            setCCTV(i + 1, cntCCTV + 1);
            change_office(cy, cx, UP, -1);
            change_office(cy, cx, LEFT, -1);
        }
        else if (type == 4)
        {
            change_office(cy, cx, UP, 1);
            change_office(cy, cx, LEFT, 1);
            change_office(cy, cx, RIGHT, 1);
            setCCTV(i + 1, cntCCTV + 1);
            change_office(cy, cx, UP, -1);
            change_office(cy, cx, LEFT, -1);
            change_office(cy, cx, RIGHT, -1);

            change_office(cy, cx, UP, 1);
            change_office(cy, cx, LEFT, 1);
            change_office(cy, cx, DOWN, 1);
            setCCTV(i + 1, cntCCTV + 1);
            change_office(cy, cx, UP, -1);
            change_office(cy, cx, LEFT, -1);
            change_office(cy, cx, DOWN, -1);

            change_office(cy, cx, DOWN, 1);
            change_office(cy, cx, LEFT, 1);
            change_office(cy, cx, RIGHT, 1);
            setCCTV(i + 1, cntCCTV + 1);
            change_office(cy, cx, DOWN, -1);
            change_office(cy, cx, LEFT, -1);
            change_office(cy, cx, RIGHT, -1);

            change_office(cy, cx, UP, 1);
            change_office(cy, cx, DOWN, 1);
            change_office(cy, cx, RIGHT, 1);
            setCCTV(i + 1, cntCCTV + 1);
            change_office(cy, cx, UP, -1);
            change_office(cy, cx, DOWN, -1);
            change_office(cy, cx, RIGHT, -1);
        }
        else
        {
            change_office(cy, cx, UP, 1);
            change_office(cy, cx, DOWN, 1);
            change_office(cy, cx, RIGHT, 1);
            change_office(cy, cx, LEFT, 1);
            setCCTV(i + 1, cntCCTV + 1);
            change_office(cy, cx, LEFT, -1);
            change_office(cy, cx, UP, -1);
            change_office(cy, cx, DOWN, -1);
            change_office(cy, cx, RIGHT, -1);
        }
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> office[i][j];
            if (office[i][j] >= 1 && office[i][j] <= 5)
            {
                v_cctv.push_back({ i, j });
                isCCTV[i][j] = office[i][j];
                office[i][j] = 0;
            }
            else if (office[i][j] == 6)
                office[i][j] = -1;
        }

    setCCTV(0, 0);
    cout << cnt_blindspot << endl;
}
