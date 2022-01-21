// 그리 어려운 문제는 아닌데 무수히 많은 뻘짓끝에 풀었다.
// 일단 이 문제가 RGB1과 다른 점은 함수를 호출할 때마다(인덱스0에서) 캐시 배열을 초기화해줘야 한다는점이다.
// 1번과 N번이 같으면 안되는 조건으로 인해서 이전 함수 호출에서의 캐시값과 현재함수 호출에서의 캐시값이 달라진다
// 이걸 몰라서 계속 해메고 있었다.
#include <bits/stdc++.h>
#define endl '\n'
#define RED 0
#define GREEN 1
#define BLUE 2
#define INF 987654321
using namespace std;
int N, first_color;
int cost[1000][3], cache[1000][3];
void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
}
int getMinCost(int idx, int color, int begin_color)
{
	if (idx == N - 1)
	{
		if (color != begin_color)
			return cost[idx][color];
		else
			return INF;
	}
	int& ret = cache[idx][color];
	if (ret != -1)
		return ret;
	if (color == RED)
		return ret = min(
			getMinCost(idx + 1, GREEN, begin_color) + cost[idx][color], getMinCost(idx + 1, BLUE, begin_color) + cost[idx][color]
		);
	else if (color == GREEN)
		return ret = min(
			getMinCost(idx + 1, RED, begin_color) + cost[idx][color], getMinCost(idx + 1, BLUE, begin_color) + cost[idx][color]
		);
	else
		return ret = min(
			getMinCost(idx + 1, RED, begin_color) + cost[idx][color], getMinCost(idx + 1, GREEN, begin_color) + cost[idx][color]
        );
}
void solve()
{
	input();
	int res = INF;
	for (int color1 = 0; color1 < 3; color1++)
	{
		fill(&cache[0][0], &cache[0][0] + 1000 * 3, -1);
		first_color = color1;
		res = min(res, getMinCost(0, color1, color1));
	}
	cout << res << endl;
}
int main()
{
	cin.tie(0)->sync_with_stdio(false);
	solve();
}
