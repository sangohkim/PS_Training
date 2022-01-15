#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N, nums[1000], cache[1000], cache2[1000];
int getLen(int start_idx)
{
	int& ret = cache[start_idx];
	if (ret != -1)
		return ret;
	ret = 1;
	for (int i = start_idx + 1; i < N; i++)
	{
		if (nums[start_idx] < nums[i])
		{
			if (getLen(i) + 1 > ret)
			{
				ret = getLen(i) + 1;
				cache2[start_idx] = i;
			}
		}
	}
	return ret;
}
int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> nums[i];
	fill(&cache[0], &cache[0] + 1000, -1);
	fill(&cache2[0], &cache2[0] + 1000, -1);
	int resLen = 0, mxidx = -1;
	for (int i = 0; i < N; i++)
	{
		int tmp = getLen(i);
		if (tmp > resLen)
		{
			resLen = tmp;
			mxidx = i;
		}
	}
	cout << resLen << endl;
	int cur_idx = mxidx;
	while (resLen)
	{
		cout << nums[cur_idx] << " ";
		cur_idx = cache2[cur_idx];
		resLen--;
	}
	cout << endl;
}
