// 후진도 불가능해졌을 때 바로 exit안 하면 답이 안나오더라....
// 왤까?
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N, M, r, c, d, cnt;
vector<vector<int>> vplace;
const int vect[4][2] = {
    {0, -1}, {1, 0}, {0, 1}, {-1, 0}
};
void input()
{
    cin >> N >> M;
    vplace = vector<vector<int>>(N, vector<int>(M, 0));
    cin >> r >> c >> d;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> vplace[i][j];
}
inline bool isOkay(int y, int x)
{
    return (0 <= y && y < N && 0 <= x && x < M && vplace[y][x] == 0);
}
void dfs(int y, int x, int dir)
{
    vplace[y][x] = 2;
    int ny, nx, cur_dir;
    for (int delta = 3; delta <= 12; delta += 3)
    {
        cur_dir = (dir + delta) % 4;
        ny = y + vect[cur_dir][1]; nx = x + vect[cur_dir][0];
        if (isOkay(ny, nx))
            dfs(ny, nx, cur_dir);
    }
    ny = y + vect[(dir + 6) % 4][1];
    nx = x + vect[(dir + 6) % 4][0];
    if (0 <= ny && ny < N && 0 <= nx && nx < M && vplace[ny][nx] != 1)
        dfs(ny, nx, dir);
    else
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (vplace[i][j] == 2) cnt++;
        cout << cnt << endl;
        exit(0);
    }
}
void solve()
{
    input();
    dfs(r, c, d);
    for (int i = 0; i < N; i++, puts(""))
        for (int j = 0; j < M; j++)
        {
            cout << vplace[i][j] << " ";
            if (vplace[i][j] == 2) cnt++;
        }
    cout << cnt << endl;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
