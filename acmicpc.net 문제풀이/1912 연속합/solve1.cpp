// 연속합 문제를 처음 보았을 때는 단순하게 반복문을 3번 중첩 시키는 것을 먼저 생각하였으나 
// 시간복잡도가 O(N^3)이어서 문제에서의 n의 상한이 10^5인 것을 보았을 때 절대 시간안에 해결이 불가능했다. 
// 그래서 시간복잡도를 O(N^2)으로 낮추는 방법을 생각하였다.
// 그 당시의 아이디어는
// 1. 가장 바깥의 원소를 통해서 n개의 모든 원소가 한 번씩 구간의 시작점이 될 수 있도록 한다.
// 2. k번째 원소가 시작점일 때 k + 1 ~ n번째 원소까지 구간이 이어질 수 있다. 그러므로 임시적인 변수를 선언하여 하나씩 더한다.
// 3. mx_sum 변수를 선언하여 tmp가 갱신될 때마다 max함수를 이용하여 mx_sum도 갱신해 나간다
// 그러나 이 방법도 시간초과를 일으켰다.(사실 n의 상한이 10^5라서 O(N^2)의 경우 1초당 10^10번 계산되어(10^8보다 작으면 대충 통과된다고 생각) 초과될 것을 짐작하고 있었다.

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<int> vint;
int N, mx_sum;

void solve()
{
	int tmp = 0;
	for (int i = 0; i < N; i++)
	{
		tmp = vint[i];
		for (int j = i + 1; j < N; j++)
		{
			tmp += vint[j];
			mx_sum = max(mx_sum, tmp);
		}
	}
	cout << mx_sum << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tmp;
	(cin >> N).get();
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		vint.push_back(tmp);
	}

	solve();

	return 0;
}
