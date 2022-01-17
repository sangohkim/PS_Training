// 아이디어는 맞았던거 같고 구현에 있어서 조금의 실수로 인해 틀렸었다.
// 우선 처음에는 가로선을 구분하자는 생각을 하지 못했었고
// N, H가 헷갈려서 배열 범위 설정을 잘못했다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N, M, H, min_added = INT_MAX;
int gameBoard[31][11];  // 내 오답 원인이 되었던 부분
int wall_cnt = 1;
void input()
{
    cin >> N >> M >> H;
    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        gameBoard[a][b] = gameBoard[a][b + 1] = wall_cnt;
        wall_cnt++;
    }
}
bool isSufficient()
{
    for (int start_col = 1; start_col <= N; start_col++)
    {
        int cur_col = start_col;
        for (int row = 1; row <= H; row++)
        {
            if (gameBoard[row][cur_col] != 0)
            {
                int num = gameBoard[row][cur_col];
                if (cur_col - 1 >= 1 && gameBoard[row][cur_col - 1] == num)
                    cur_col--;
                else if (cur_col + 1 <= N && gameBoard[row][cur_col + 1] == num)
                    cur_col++;
            }
        }
        if (cur_col != start_col)
            return false;
    }
    return true;
}
bool isAddable(int a, int b)
{
    return (b + 1 <= N && gameBoard[a][b] == 0 && gameBoard[a][b + 1] == 0);
}
void add_column(int idxNum, int cur, int limit)
{
    if (cur == limit)
    {
        if (isSufficient())
        {
            min_added = min(min_added, limit - wall_cnt);
            puts("");
            for (int i = 1; i <= H; i++, puts(""))
                for (int j = 1; j <= N; j++)
                    cout << gameBoard[i][j] << " ";
            cout << isSufficient() << endl;
            puts("");
        }
        // start
        /*
        puts("");
        for (int i = 1; i <= H; i++, puts(""))
            for (int j = 1; j <= N; j++)
                cout << gameBoard[i][j] << " ";
        cout << isSufficient() << endl;
        puts("");
        */
        // end
        return;
    }
    for (int i = idxNum; i < N * H; i++)
    {
        int cur_c = i % N + 1, cur_r = i / N + 1;
        if (isAddable(cur_r, cur_c))
        {
            gameBoard[cur_r][cur_c] = gameBoard[cur_r][cur_c + 1] = cur + 1;
            add_column(i + 1, cur + 1, limit);
            gameBoard[cur_r][cur_c] = gameBoard[cur_r][cur_c + 1] = 0;
        }
    }
}
void solve()
{
    input();
    for (int i = 0; i < 4; i++)
    {
        add_column(0, wall_cnt, i + wall_cnt);

    }
    if (min_added == INT_MAX)
        cout << -1 << endl;
    else
        cout << min_added << endl;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
