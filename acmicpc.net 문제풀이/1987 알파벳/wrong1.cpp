// 기본적으로 이문제는 완전탐색으로는 많은 시간이 걸린다.
// 근데 특히 방문 여부를 확인하는 부분에 반복문을 써서 시간초과가 된 것 같다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int R, C, mx_cnt = INT_MIN;
vector<vector<char>> board;
vector<char> vpath;
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
    string stmp;

    for (auto ch : vpath) stmp += ch;
    if (stmp.find(alpha) == string::npos)
        return false;
    return true;
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
        vpath.push_back(board[ny][nx]);
        solve(ny, nx, spaceCount + 1);
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
    solve(0, 0, 1);
    cout << mx_cnt << endl;
}
