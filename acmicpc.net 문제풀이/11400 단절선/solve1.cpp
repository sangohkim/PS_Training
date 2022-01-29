// 단절점과 비슷한 문제였는데 왜 나는 뻘짓을 하고 있었을까...
// 핵심 아이디어는 (u, v)간선만 제외하고 역방향간선을 조사하는것
// (u, v)간선을 제외하기 위해서 부모노드번호를 저장하는 매개변수를 추가로 설정해주었다.
// 처음에는 단절선의 양 끝 정점은 모두 단절점이 되어야 한다는 생각에 단절점을 찾고
// 그 단절점 사이에서 연결된것들끼리 출력했는데 틀렸더라...
// 반례는 찾아봐야 겠고 어쨋든 종만북의 도움을 받아 풀게 되었다.
// 트리 간선만이 다리가 될 수 있다는 것까지는 캐치했었는데 그 다음에 그걸 확인하는 작업을 비효율적으로 구상한거 같다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int> Pair;
int V, E, counter;
vector<vector<int>> adj;
vector<int> discovered;
vector<Pair> vres;
void input()
{
    cin >> V >> E;
    adj = vector<vector<int>>(V + 1);
    discovered = vector<int>(V + 1, -1);
    int a, b;
    for (int i = 1; i <= E; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}
int findCutVertex(int here, int parent)
{
    discovered[here] = counter++;
    int ret = discovered[here];
    for (int i = 0; i < adj[here].size(); i++)
    {
        int there = adj[here][i];
        if (there == parent) continue;
        if (discovered[there] == -1)
        {
            int subtree = findCutVertex(there, here);
            if (subtree > discovered[here])
                vres.push_back(make_pair((here < there ? here : there), (here > there ? here : there)));
            ret = min(ret, subtree);
        }
        else
            ret = min(ret, discovered[there]);
    }
    return ret;
}
void solve()
{
    input();
    findCutVertex(1, -1);
    sort(vres.begin(), vres.end());
    cout << vres.size() << endl;
    for (auto p : vres) cout << p.first << " " << p.second << endl;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
