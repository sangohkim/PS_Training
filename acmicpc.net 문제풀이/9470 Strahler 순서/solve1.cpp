// 그냥 그래프를 서로 방향성이 반대인 두 개를 만들어서 정점마다 strahler순서를 다 구했다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int T, K, M, P;
int inDegree[1001], strahler[1001];
vector<int> vgraph[1001];
vector<int> vgraph2[1001];
int getStrahler(int nodenum)
{
    int mxvalue = INT_MIN;
    vector<int> vtmp;
    for (int i = 0; i < vgraph2[nodenum].size(); i++)
    {
        mxvalue = max(mxvalue, strahler[vgraph2[nodenum][i]]);
        vtmp.push_back(strahler[vgraph2[nodenum][i]]);
    }
    if (count(vtmp.begin(), vtmp.end(), mxvalue) >= 2)
        return mxvalue + 1;
    else
        return mxvalue;
}
void init()
{
    fill(&inDegree[0], &inDegree[0] + 1001, 0);
    fill(strahler, strahler + 1001, 0);
    for (int i = 1; i <= 1000; i++)
    {
        fill(vgraph[i].begin(), vgraph[i].end(), 0);
        fill(vgraph2[i].begin(), vgraph2[i].end(), 0);
    }
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
        vgraph2[B].push_back(A);
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
                if (inDegree[next] == 0)
                    q.push(next);
                strahler[next] = getStrahler(next);
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
