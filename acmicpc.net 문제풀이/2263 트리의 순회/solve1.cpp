// 하.....
// 아이디어 맞았는데
// 인덱스 갱신할 때 초기 인덱스에다 더해야 되는거 계속 놓쳐서 여러번 틀렸다.....
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N;
vector<int> vin, vpost;
void input()
{
	cin >> N;
	int tmp;
	for (int i = 1; i <= N; i++)
	{
		cin >> tmp;
		vin.push_back(tmp);
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> tmp;
		vpost.push_back(tmp);
	}
}
void printPreOrder(int iidx1, int iidx2, int pidx1, int pidx2)
{
	if (iidx1 > iidx2 || pidx1 > pidx2)
		return;
	int root = vpost[pidx2];
	int root_idx = find(vin.begin() + iidx1, vin.begin() + iidx2 + 1, root) - (vin.begin() + iidx1);
	cout << root << " ";
	printPreOrder(iidx1, iidx1 + root_idx - 1, pidx1, pidx1 + root_idx - 1);
	printPreOrder(iidx1 + root_idx + 1, iidx2, pidx1 + root_idx, pidx2 - 1);
}
void solve()
{
	input();
	printPreOrder(0, N - 1, 0, N - 1);
}
int main()
{
	cin.tie(0)->sync_with_stdio(false);
	solve();
}
