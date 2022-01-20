// 위상 정렬을 통해서 풀 수 있었던 문제
// 예전에 풀었던 게임개발 ACM CRAFT도 위상정렬을 이용할수도 있다고 한다.
// 위상정렬은 순서가 있는 것들을 올바르게 모두 나열할 때 유용하다는 것을 기억해놓아야 겠다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N, M;
int inDegree[32001];
vector<int> vgraph[32001];
vector<int> vres;
void topologySort()
{
	queue<int> q;
	
	for (int i = 1; i <= N; i++)
		if (inDegree[i] == 0)
			q.push(i);
	for (int n = 1; n <= N; n++)
	{
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 0; i < vgraph[cur].size(); i++)
		{
			int target = vgraph[cur][i];
			inDegree[target]--;
			if (inDegree[target] == 0)
				q.push(target);
		}
	}
	cout << endl;
}
void input()
{
	cin >> N >> M;
	int A, B;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		inDegree[B]++;
		vgraph[A].push_back(B);
	}
}
void solve()
{
	input();
	topologySort();
}
int main()
{
	cin.tie(0)->sync_with_stdio(false);
	solve();
}
