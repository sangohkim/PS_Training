// solve1이 실패하고 난 후에 동적계획법을 이용하는 방법에 대해서 생각하게 되었다.
// 원리는 아래와 같다.
// max_sum[i] 정의: i번째 원소가 가장 오른쪽에 있는 연속 부분 구간의 최대합
// 이때 max_sum[i] = max(max_sum[i - 1], 0) + vint[i] 와 같다는 것을 알 수 있다.
// 시간복잡도는 중첩없는 반복문이 지배적이니 O(N)이 된다.

// 분할정복을 이용하면 조금 더 빠르게 해결된다고 하는데 이는 다음에 알아봐야 겠다.

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
int mx_sum = INT_MIN;
vector<int> vint;

void input()
{
	int tmp;
	(cin >> n).get();
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		vint.push_back(tmp);
	}
}

void solve()
{
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		tmp = max(0, tmp) + vint[i];
		mx_sum = max(tmp, mx_sum);
	}
	cout << mx_sum << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}
