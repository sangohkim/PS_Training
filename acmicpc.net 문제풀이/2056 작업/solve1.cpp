// 시간 관련 배열을 두 개 만들어서 갱신한다는 것을 잘 기억해두어야 겠다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N;
int spentTime[10001], inDegree[10001], max_time[10001];
vector<int> vgraph[10001];
void input()
{
    cin >> N;
    int M, tmp;
    for (int i = 1; i <= N; i++)
    {
        cin >> spentTime[i] >> M;
        max_time[i] = spentTime[i];
        inDegree[i] += M;
        for (int j = 1; j <= M; j++)
        {
            cin >> tmp;
            vgraph[tmp].push_back(i);
        }
    }
}
void solve()
{
    input();
    queue<int> q;
    for (int i = 1; i <= N; i++)
        if (inDegree[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < vgraph[cur].size(); i++)
        {
            int target = vgraph[cur][i];
            inDegree[target]--;
            if (inDegree[target] == 0)
                q.push(target);
            max_time[target] = max(max_time[target], max_time[cur] + spentTime[target]);
        }
    }
    cout << *max_element(max_time + 1, max_time + N + 1) << endl;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
