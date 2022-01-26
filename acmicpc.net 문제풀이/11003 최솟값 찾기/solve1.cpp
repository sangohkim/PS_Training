// 나는 while문 쓰는게 시간이 더 오래 걸릴거라고 생각했는데 아니었다.....
// 내 시간초과 코드랑 나중에 비교해봐야 겠다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N, L;
void solve()
{
	cin >> N >> L;
	deque<pair<int, int>> dq;
	int num;
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		if (!dq.empty() && dq.front().second < i - L + 1)
			dq.pop_front();
		while (!dq.empty() && dq.back().first > num)
			dq.pop_back();
		dq.push_back(make_pair(num, i));
		cout << dq.front().first << " ";
	}
}
int main()
{
	cin.tie(0)->sync_with_stdio(false);
	solve();
}
