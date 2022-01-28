// 일단 오답원인부터 분석해본다면
// "문제를 대충 읽었기 때문"
// 비행기가 순서대로 들어온다는 지문 내용을 숙지를 못해서
// 우선순위 큐를 썼다가 계속 틀렸다.
// 사실 그냥 큐를 쓰면 됬는데....
// 알고리즘을 보니까 분리집합이라고 되어있던데 어떤건지 한번 알아봐야 겠다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int G, P, cnt;
typedef pair<int, int> PairInt;
queue<PairInt> q;
set<int> gates;
void init()
{
	cin >> G;
	cin >> P;
	int g;
	for (int p = 1; p <= P; p++)
	{
		cin >> g;
		q.push(make_pair(g, p));
	}
	for (int i = 1; i <= G; i++)
		gates.insert(i);
}
void solve()
{
	init();
	while (!gates.empty() && !q.empty())
	{
		auto iter1 = gates.find(q.front().first);
		if (iter1 != gates.end())
		{
			q.pop();
			gates.erase(*iter1);
			cnt++;
		}
		else
		{
			auto iter2 = gates.upper_bound(q.front().first);
			if (iter2 == gates.begin())
				return;
			--iter2;
			q.pop();
			gates.erase(*iter2);
			cnt++;
		}
	}
}
int main()
{
	cin.tie(0)->sync_with_stdio(false);
	solve();
	cout << cnt << endl;
}
