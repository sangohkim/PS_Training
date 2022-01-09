// 방문 확인 부분에서 반복문 대신 다른 방법을 사용하여 시간초과를 피하였다.
// 나중에 그래프 탐색 등을 배우면 더 잘 해결될 것 같다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int R, C, mx_cnt = INT_MIN;
vector<vector<char>> board;
vector<char> vpath;
vector<int> visited(26);
const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0, 1 };

void input()
{
    (cin >> R >> C).get();
    for (int r = 0; r < R; r++)
    {
        vector<char> vtmp(C);
        for (int c = 0; c < C; c++)
            cin >> vtmp[c];
        board.push_back(vtmp);
    }
}

bool isVisited(char alpha)
{
    return visited[alpha - 'A'];
}

void solve(int y, int x, int spaceCount)
{
    int ny, nx;
    for (int i = 0; i < 4; i++)
    {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || ny >= R || nx < 0 || nx >= C || isVisited(board[ny][nx]))
            continue;
        char newAlpha = board[ny][nx];
        vpath.push_back(newAlpha);
        visited[newAlpha - 'A'] = 1;
        solve(ny, nx, spaceCount + 1);
        visited[newAlpha - 'A'] = 0;
        vpath.pop_back();
    }
    mx_cnt = max(mx_cnt, spaceCount);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    vpath.push_back(board[0][0]);
    visited[board[0][0] - 'A'] = 1;
    solve(0, 0, 1);
    cout << mx_cnt << endl;
}
