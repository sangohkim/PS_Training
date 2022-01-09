// 마지막에 방문하는 도시가 시작점인 도시와 연결되어있는지 확인해야 되는데
// 그걸 안해서 계속 틀렸다!!!!

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int N, min_cost = INT_MAX;
vector<vector<int>> costs;
vector<int> visited(10, 0);
vector<int> path;

void solve(int cur_cost)
{
	if (path.size() == N)
	{
        if (costs[path.back()][path.front()])
		    min_cost = min(min_cost, cur_cost + costs[path.back()][path.front()]);
		return;
	}

	for (int city = 1; city < N; city++)
	{
		if (visited[city] || !costs[path.back()][city])
			continue;
		int cur = path.back();
		path.push_back(city);
		visited[city] = true;
		solve(cur_cost + costs[cur][city]);
		visited[city] = false;
		path.pop_back();
	}
}

void input()
{
	bool isOneExist = false;
	(cin >> N).get();
	for (int i = 0; i < N; i++)
	{
		vector<int> vtmp(N);
		for (int j = 0; j < N; j++)
		{
			cin >> vtmp[j];
			if (vtmp[j]) isOneExist = true;
		}
		costs.push_back(vtmp);
	}
	if (!isOneExist)
		min_cost = 0;
	else
	{
		path.push_back(0);
		visited[0] = 1;
		solve(0);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();

	cout << min_cost << endl;
}
