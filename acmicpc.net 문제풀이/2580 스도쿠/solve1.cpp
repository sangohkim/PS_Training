// 숫자가 추가 가능한지 확인하는 반복문을 돌릴 때 시간초과가 안나도록
// for문이 최대한 빠르게 끝나게 해야 하는 것이 중요한듯(완전탐색으로 풀려면)

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<vector<int>> board;
const int dxdy[3][3] = {
    {0, 1, 2}, {-1, 0, 1}, {-2, -1, 0},
};

void input()
{
    for (int i = 0; i < 9; i++)
    {
        vector<int> vtmp(9);
        for (int j = 0; j < 9; j++)
            cin >> vtmp[j];
        board.push_back(vtmp);
    }
}

void vShow()
{
    for (auto x : board)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
}

bool check(int y, int x, int val)
{
    for (int i = 0; i < 9; i++)
        if (board[y][i] == val || board[i][x] == val)
            return false;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            if (board[y + dxdy[y % 3][i]][x + dxdy[x % 3][j]] == val)
                return false;
    }
    return true;
}

void solve()
{
    int y = -1, x = -1;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            if (!board[i][j])
            {
                y = i; x = j;
                break;
            }
        if (y != -1) break;
    }
    if (y == -1)
    {
        vShow();
        exit(0);
    }

    for (int num = 1; num <= 9; num++)
    {
        if (!check(y, x, num))
            continue;
        board[y][x] = num;
        solve();
        board[y][x] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
}
