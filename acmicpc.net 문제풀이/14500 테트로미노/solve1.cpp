#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N, M, mx_sum;
int paper[500][500], isVisited[500][500];
const int d[4][2] = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}
};
void makeTetro(int cury, int curx, int curBlocks, int curSum)
{
    if (curBlocks >= 4)
    {
        mx_sum = max(mx_sum, curSum);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int newy = cury + d[i][0], newx = curx + d[i][1];
        if (0 <= newy && newy < N && 0 <= newx && newx < M && !isVisited[newy][newx])
        {
            isVisited[newy][newx] = 1;
            makeTetro(newy, newx, curBlocks + 1, curSum + paper[newy][newx]);
            isVisited[newy][newx] = 0;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> paper[i][j];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            isVisited[i][j] = 1;
            makeTetro(i, j, 1, paper[i][j]);
            isVisited[i][j] = 0;
            int tmp;
            int curx = j, cury = i;
            if (0 <= curx - 1 && curx - 1 < M && 0 <= curx + 1 && curx + 1 < M)
            {
                if (0 <= cury - 1 && cury - 1 < N)
                {
                    tmp = paper[cury][curx - 1] + paper[cury][curx] + paper[cury][curx + 1] + paper[cury - 1][curx];
                    mx_sum = max(mx_sum, tmp);
                }
                if (0 <= cury + 1 && cury + 1 < N)
                {
                    tmp = paper[cury][curx - 1] + paper[cury][curx] + paper[cury][curx + 1] + paper[cury + 1][curx];
                    mx_sum = max(mx_sum, tmp);
                }
            }
            if (0 <= cury - 1 && cury - 1 < N && 0 <= cury + 1 && cury + 1 < N)
            {
                if (0 <= curx - 1 && curx - 1 < M)
                {
                    tmp = paper[cury][curx - 1] + paper[cury][curx] + paper[cury + 1][curx] + paper[cury - 1][curx];
                    mx_sum = max(mx_sum, tmp);
                }
                if (0 <= curx + 1 && curx + 1 < M)
                {
                    tmp = paper[cury][curx + 1] + paper[cury][curx] + paper[cury + 1][curx] + paper[cury - 1][curx];
                    mx_sum = max(mx_sum, tmp);
                }
            }
        }
    cout << mx_sum << endl;
}
