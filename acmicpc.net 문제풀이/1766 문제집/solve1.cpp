// 예전에는 정렬한다고 별짓을 다 하다가 시간초과났는데
// 우선순위큐를 알게 되고 나서 푸니까 그냥 풀린다.....
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N, M;
vector<int> inDegree(32001, 0);
vector<vector<int>> adj;
void topologicalSort()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; i++)
        if (inDegree[i] == 0)
            pq.push(i);
    while (!pq.empty())
    {
        int cur = pq.top();
        cout << cur << " ";
        pq.pop();
        for (int i = 0; i < adj[cur].size(); i++)
        {
            int next = adj[cur][i];
            inDegree[next]--;
            if (inDegree[next] == 0) pq.push(next);
        }
    }
}
void init()
{
    cin >> N >> M;
    int a, b;
    adj = vector<vector<int>>(N + 1);
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        inDegree[b]++;
        adj[a].push_back(b);
    }
    topologicalSort();
}
void solve()
{
    init();
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
