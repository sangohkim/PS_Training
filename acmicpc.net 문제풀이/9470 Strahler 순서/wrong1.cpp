// 위상정렬부분은 오류가 없으나 strahler 순서 찾는 부분에서 문제가 있었다.
// 
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int T, K, M, P;
int inDegree[1001], strahler[1001], max_cnt[1001];
vector<int> vgraph[1001];
void init()
{
    fill(&inDegree[0], &inDegree[0] + 1001, 0);
    fill(strahler, strahler + 1001, 0);
    fill(max_cnt, max_cnt + 1001, 0);
    for (int i = 1; i <= 1000; i++)
        fill(vgraph[i].begin(), vgraph[i].end(), 0);
}
void input()
{
    cin >> K >> M >> P;
    int A, B;
    for (int p = 1; p <= P; p++)
    {
        cin >> A >> B;
        inDegree[B]++;
        vgraph[A].push_back(B);
    }
}
void solve()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        init();
        input();
        vector<int> vres;
        queue<int> q;
        for (int i = 1; i <= M; i++)
            if (inDegree[i] == 0)
            {
                q.push(i);
                strahler[i] = 1;
            }
        while (!q.empty())
        {
            int cur = q.front();
            vres.push_back(cur);
            q.pop();
            for (int i = 0; i < vgraph[cur].size(); i++)
            {
                int next = vgraph[cur][i];
                inDegree[next]--;
                if (strahler[next] < strahler[cur])
                {
                    strahler[next] = strahler[cur];
                    max_cnt[next] = 1;
                }
                else if (strahler[next] == strahler[cur])
                {
                    max_cnt[next]++;
                    if (max_cnt[next] >= 2)
                    {
                        strahler[next]++;
                        max_cnt[next] = 1;
                    }
                }
                if (inDegree[next] == 0)
                    q.push(next);
            }
        }
        cout << K << " " << strahler[vres.back()] << endl;
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
