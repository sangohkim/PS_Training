// 전체적인 풀이 방향은 맞았는데
// 오답이 발생했던 이유는 처음에는 (0, 0)으로 호출했다.
// 근데 저렇게 호출하면 안되는 이유는 인덱스0의 숫자가 0보다 큰 경우에는 빼면 음수가 되서 카운트가 안되지만
// 0이되면 빼도 범위를 만족한다. 즉 중복되어 카운트되는 것이다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int N;
int nums[100];
ll cache[100][21];
void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> nums[i];
}
ll makeEqual(int start_idx, ll cur)
{
	if (start_idx == N - 1)
	{
		if (cur == nums[N - 1])
			return 1;
		else
			return 0;
	}
	ll& ret = cache[start_idx][cur];
	if (ret != -1)
		return ret;
	ret = 0;
	ll next = cur + nums[start_idx];
	if (next >= 0 && next <= 20)
		ret += makeEqual(start_idx + 1, next);
	next = cur - nums[start_idx];
	if (next >= 0 && next <= 20)
		ret += makeEqual(start_idx + 1, next);
	return ret;
}
void solve()
{
	input();
	fill(&cache[0][0], &cache[0][0] + 100 * 21, -1);
	cout << makeEqual(1, nums[0]) << endl;  // 이 부분에서 했던 조그마한 실수때문에 틀리고 있었다.
}
int main()
{
	cin.tie(0)->sync_with_stdio(false);
	solve();
}
