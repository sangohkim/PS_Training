// 일단 분할정복 아이디어는 맞았음
// 근데 정말 사소한 구현실수 때문에 엄청 헤맸음(i, j가 아닌 y, x를 값 검사할때 썼다는거!!!)
// 풀었는데도 찜찜한 기분
#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(false)
using namespace std;
int N;
int picture[64][64];
void getCompressed(int y, int x, int length)
{
    if (length == 1)
    {
        cout << picture[y][x];
        return;
    }
    bool isAllOne = true, isAllZero = true;
    for (int i = y; i < y + length; i++)
        for (int j = x; j < x + length; j++)
        {
            if (picture[i][j] == 0) isAllOne = false;
            if (picture[i][j] == 1) isAllZero = false;
        }
    if (isAllOne == true)
    {
        cout << 1;
        return;
    }
    if (isAllZero == true)
    {
        cout << 0;
        return;
    }
    cout << "(";
    getCompressed(y, x, length / 2);
    getCompressed(y, x + length / 2, length / 2);
    getCompressed(y + length / 2, x, length / 2);
    getCompressed(y + length / 2, x + length / 2, length / 2);
    cout << ")";
}
int main()
{
    fastio;
    cin >> N;
    char ch;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> ch;
            picture[i][j] = ch - '0';
        }
    getCompressed(0, 0, N);
}
