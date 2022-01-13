// bfs 대신에 어차피 치킨집의 개수가 몇개 되지도 않으니 그냥 하나씩 비교해가면서 최소를 찾는 방식으로 변경 후 성공
// 항상 "무식하게 풀 수는 없을까?"라는 질문을 해야 겠다
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N, M, arrNoChick[50][50], mn_dist = INT_MAX, isUsed[50][50];
const int d[4][2] = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}
};
vector<pair<int, int>> chicken;
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
                    int tmp = INT_MAX;
                    for (int k = 0; k < chicken.size(); k++)
                    {
                        int cy = chicken[k].first, cx = chicken[k].second;
                        if (arrNoChick[cy][cx] == 2)
                        {
                            tmp = min(tmp, abs(cy - i) + abs(cx - j));
                        }
                    }
                    res += tmp;
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
            isUsed[ny][nx] = 1;
            getMinDist(i, cntChick + 1);
            arrNoChick[ny][nx] = 0;
            isUsed[ny][nx] = 0;
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
