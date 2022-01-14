// enum을 한번 사용해서 편리하게 해볼려고 했지만
// 오히려 헷갈려서 푸는데 생각보다 좀 걸린듯한 문제
// 풀이에 핵심적인 아이디어 잡는데는 금방이었는데.......
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N, house[16][16], ways;
const int d[3][2] = {
	{0, 1}, {1, 0}, {1, 1}
};
enum State { V, H, D };
bool isOkay(int y, int x)
{
	return (0 <= y && y < N && 0 <= x && x < N && house[y][x] != 1);
}
void movePipe(State cur, int y, int x)
{
	int cy = y + d[cur][1], cx = x + d[cur][0];
	if (cy == N - 1 && cx == N - 1)
	{
		if (isOkay(cy, cx))
		{
			ways++;
		}
		return;
	}
	int ny = cy + d[D][1], nx = cx + d[D][1];
	if (isOkay(ny, nx) && isOkay(ny - 1, nx) && isOkay(ny, nx - 1))
		movePipe(D, cy, cx);
	if (cur == D)
	{
		for (int i = 0; i < 2; i++)
		{
			ny = cy + d[i][1];
			nx = cx + d[i][0];
			if (isOkay(ny, nx))
				movePipe((State)i, cy, cx);
		}
	}
	else if (cur == V)
	{
		ny = cy + d[V][1];
		nx = cx + d[V][0];
		if (isOkay(ny, nx))
			movePipe(V, cy, cx);
	}
	else
	{
		ny = cy + d[H][1];
		nx = cx + d[H][0];
		if (isOkay(ny, nx))
			movePipe(H, cy, cx);
	}
}
int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> house[i][j];
	movePipe(H, 0, 0);
	cout << ways << endl;
}
