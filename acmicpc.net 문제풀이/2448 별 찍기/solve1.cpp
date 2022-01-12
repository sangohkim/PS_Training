#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(false)
#define endl '\n'
using namespace std;
int N, stars[3072][6143];
void draw(int y, int x, int Size)
{
	if (Size == 3)
	{
		stars[y][x] = 1;
		stars[y + 1][x - 1] = stars[y + 1][x + 1] = 1;
		for (int j = x - 2; j <= x + 2; j++)
			stars[y + 2][j] = 1;
		return;
	}
	int xN = (2 * Size - 1) / 2;
	draw(y, x, Size / 2);
	draw(y + Size / 2, x - xN / 2 - 1, Size / 2);
	draw(y + Size / 2, x + xN / 2 + 1, Size / 2);
}
int main()
{
	cin >> N;
	draw(0, (2 * N - 1) / 2, N);
	for (int i = 0; i < N; i++, puts(""))
		for (int j = 0; j < 2 * N - 1; j++)
		{
			if (stars[i][j] == 1)
				cout << "*";
			else
				cout << " ";
        }       
}
