// 이때까지 틀렸던 원인
// 1. 처음에는 map을 사용하자는 아이디어 없이 그냥 했다가 시간초과
// 2. map을 사용했었는데 중복되는 경우가 있을 수 있다는거 놓침(직접적인 오답요인인지는 모르겠음)
// 3. 방식은 맞았으나 오버플로우 고민하는 것 놓침
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N, K;
typedef long long ll;
typedef pair<ll, ll> Pair;
struct cmp {
	bool operator()(Pair p1, Pair p2)
	{
		if (p2.second > p1.second)
			return true;
		else if (p2.second == p1.second && p2.first < p1.first)
			return true;
		return false;
	}
};
void solve()
{
	cin >> N >> K;
	priority_queue<Pair, vector<Pair>, cmp> pq;
	map<ll, ll> weight;
	ll mi, vi, ci;
	for (int i = 1; i <= N; i++)
	{
		cin >> mi >> vi;
		pq.push(make_pair(mi, vi));
	}
	for (int i = 1; i <= K; i++)
	{
		cin >> ci;
		weight[ci]++;
	}
	ll tot = 0;
	while (!weight.empty() && !pq.empty())
	{
		auto iter = weight.lower_bound(pq.top().first);
		if (iter == weight.end())
		{
			pq.pop();
			continue;
		}
		tot += pq.top().second;
		pq.pop();
		if ((--weight[iter->first]) == 0)
		    weight.erase(iter->first);
	}
	cout << tot << endl;
}
int main()
{
	cin.tie(0)->sync_with_stdio(false);
	solve();
}
