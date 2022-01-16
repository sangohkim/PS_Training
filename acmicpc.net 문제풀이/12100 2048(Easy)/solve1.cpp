// 나는 노가다코딩으로 풀긴했는데
// 다른 사람은 어떻게 풀었는지 나중에 확인해봐야 
#include <bits/stdc++.h>
#define endl '\n'
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
using namespace std;
int N, mxNum = INT_MIN;
int initBoard[20][20];
void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> initBoard[i][j];
}
int findMax(int (*target)[20])
{
    int res = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            res = max(res, target[i][j]);
    return res;
}
void updateBoard(int (*target)[20], int direction)
{
    if (direction == LEFT)
    {
        for (int i = 0; i < N; i++)
        {
            vector<int> vrow, vres;
            for (int j = 0; j < N; j++)
            {
                if (target[i][j] != 0)
                {
                    vrow.push_back(target[i][j]);
                    target[i][j] = 0;
                }
            }
            int idx = 0;
            while (idx < vrow.size())
            {
                if (idx + 1 < vrow.size() && vrow[idx] == vrow[idx + 1])
                {
                    vres.push_back(vrow[idx] + vrow[idx + 1]);
                    idx += 2;
                }
                else
                {
                    vres.push_back(vrow[idx]);
                    idx++;
                }
            }
            for (int k = 0; k < vres.size(); k++)
                target[i][k] = vres[k];
        }
    }
    else if (direction == RIGHT)
    {
        for (int i = 0; i < N; i++)
        {
            vector<int> vrow, vres;
            for (int j = 0; j < N; j++)
            {
                if (target[i][j] != 0)
                {
                    vrow.push_back(target[i][j]);
                    target[i][j] = 0;
                }
            }
            int idx = vrow.size() - 1;
            while (idx >= 0)
            {
                if (idx - 1 >= 0 && vrow[idx] == vrow[idx - 1])
                {
                    vres.push_back(vrow[idx] + vrow[idx - 1]);
                    idx -= 2;
                }
                else
                {
                    vres.push_back(vrow[idx]);
                    idx--;
                }
            }
            for (int k = 0; k < vres.size(); k++)
                target[i][N - 1 - k] = vres[k];
        }
    }
    else if (direction == DOWN)
    {
        for (int j = 0; j < N; j++)
        {
            vector<int> vcol, vres;
            for (int i = 0; i < N; i++)
            {
                if (target[i][j] != 0)
                {
                    vcol.push_back(target[i][j]);
                    target[i][j] = 0;
                }
            }
            int idx = vcol.size() - 1;
            while (idx >= 0)
            {
                if (idx - 1 >= 0 && vcol[idx] == vcol[idx - 1])
                {
                    vres.push_back(vcol[idx] + vcol[idx - 1]);
                    idx -= 2;
                }
                else
                {
                    vres.push_back(vcol[idx]);
                    idx--;
                }
            }
            for (int k = 0; k < vres.size(); k++)
                target[N - 1 - k][j] = vres[k];
        }
    }
    else if (direction == UP)
    {
        for (int j = 0; j < N; j++)
        {
            vector<int> vcol, vres;
            for (int i = 0; i < N; i++)
            {
                if (target[i][j] != 0)
                {
                    vcol.push_back(target[i][j]);
                    target[i][j] = 0;
                }
            }
            int idx = 0;
            while (idx < vcol.size())
            {
                if (idx + 1 < vcol.size() && vcol[idx] == vcol[idx + 1])
                {
                    vres.push_back(vcol[idx] + vcol[idx + 1]);
                    idx += 2;
                }
                else
                {
                    vres.push_back(vcol[idx]);
                    idx++;
                }
            }
            for (int k = 0; k < vres.size(); k++)
                target[k][j] = vres[k];
        }
    }
}
void moveBlocks(int move_cnt, int curBoard[20][20], int prev)
{
    if (move_cnt == 5)
    {
        mxNum = max(mxNum, findMax(curBoard));
        return;
    }
    int nextBoard[20][20];
    for (int type = 0; type < 4; type++)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                nextBoard[i][j] = curBoard[i][j];
        updateBoard(nextBoard, type);
        moveBlocks(move_cnt + 1, nextBoard, type);
    }
}
void solve()
{
    input();
    moveBlocks(0, initBoard, -1);
    cout << mxNum << endl;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
