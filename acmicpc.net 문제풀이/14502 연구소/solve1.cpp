// 우여곡절 끝에 푼 문제
// 배열을 처음부터 완전탐색하는 경우에 배열의 행과 열을 몫과 나머지를 이용해서 구하는 방법도 있다는 점, 그리고 copy의 범위를 적을 때 past-the-end임을 고려하기!!!
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N, M, Map[8][8], mxcnt, copiedMap[8][8];
const int d[4][2] = {
	{-1, 0}, {1, 0}, {0, 1}, {0, -1}
};
vector<vector<int>> virus;
void dfs(int y, int x)
{
	copiedMap[y][x] = 2;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + d[i][0], nx = x + d[i][1];
		if (0 <= ny && ny < N && 0 <= nx && nx < M && copiedMap[ny][nx] == 0)
			dfs(ny, nx);
	}
}
void makeWall(int num, int wallcnt)
{
	if (wallcnt == 3)
	{
		copy(&Map[0][0], &Map[0][0] + 64, &copiedMap[0][0]);
		for (int i = 0; i < virus.size(); i++)
			dfs(virus[i][0], virus[i][1]);
		int res = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (copiedMap[i][j] == 0)
					res++;
		mxcnt = max(mxcnt, res);
		return;
	}
	for (int i = num; i < N * M; i++)
	{
		int cy = i / M, cx = i % M;
		if (Map[cy][cx] == 0)
		{
			Map[cy][cx] = 1;
			makeWall(i, wallcnt + 1);
			Map[cy][cx] = 0;
		}
	}
}
int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 2)
				virus.push_back({ i, j });
		}
	makeWall(0, 0);
	cout << mxcnt << endl;
}
