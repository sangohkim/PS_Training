// 이분탐색으로도 LIS 결과까지 구하기 가능
#include <bits/stdc++.h>
#define endl '\n'
#define MAX 500000
using namespace std;
int N;
vector<int> vnums(MAX + 1, 0);
vector<int> vindex(MAX + 1, 0);
void input()
{
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		vnums[b] = a;
	}
	vector<int> vres;
	int idx;
	for (int i = 1; i <= MAX; i++)
	{
		if (!vnums[i]) continue;
		if (vres.empty() || vnums[i] > vres.back())
		{
			vres.push_back(vnums[i]);
			vindex[i] = vres.size();
		}
		else
		{
			idx = lower_bound(vres.begin(), vres.end(), vnums[i]) - vres.begin();
			vres[idx] = vnums[i];
			vindex[i] = idx + 1;
		}
	}
	int tot = vres.size();
	cout << N - tot << endl;
	int i = MAX;
	for (int len = tot; len >= 1; len--)
	{
		while (vindex[i] != len) --i;
		vindex[i] = -1;
	}
	vector<int> vdel;
	for (int i = 1; i <= MAX; i++)
		if (vindex[i] != -1 && vnums[i] != 0)
			vdel.push_back(vnums[i]);
	sort(vdel.begin(), vdel.end());
	for (auto n : vdel) cout << n << endl;
}
void solve()
{
	input();
}
int main()
{
	cin.tie(0)->sync_with_stdio(false);
	solve();
}
