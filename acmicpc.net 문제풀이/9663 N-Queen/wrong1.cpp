// 일단 오늘 일어나서 몇 시간을 헤매다가 풀게 됬다.
// 처음에는 하나의 퀸을 놓는 걸 하나의 조각으로 생각해서 그걸 재귀함수로 해서 구현할려고 했다.
// 근데 분명히 대각선 확인하는 것까지 맞게 구현했는데 처음에는 (0, 0)에 놓는 경우와 그렇지 않은 경우가 있다는걸
// 인지하지 못해서 계속 경우가 1 or 0이 나왔다. 그래서 원래는 가장 왼쪽 위에 값이 0 인 위치를 구해서 그
// 위치를 1로 만들고 실행했는데 그것도 하면서 0으로 놔두고 실행하는 것도 같이 했다.
// 그래서 될 줄 알았는데 갑자기 경우의 수가 너무 커지는 것이다. 알고 보니 가장 왼쪽 위 0인 좌표를 찾는거 때문에
// 경우의 수가 결국은 중복되는 것이다. 어쩔줄 모르고 해메다가
// 1차원 배열쓰는 방식으로 바꾸어서 해결하게 되었다.

#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.tie(0)->sync_with_stdio(false);
using namespace std;

int N, cnt, board[15];

void wayCount(int qcnt)
{
    if (qcnt == N)
    {
        cnt++;
        return;
    }
    for (int row = 0; row < N; row++)
    {
        bool isPossible = true;
        for (int col = 0; col < qcnt; col++)
            if (board[col] == row || abs(qcnt - col) == abs(row - board[col]))
            {
                isPossible = false;
                break;
            }
        if (isPossible)
        {
            board[qcnt] = row;
            wayCount(qcnt + 1);
            board[qcnt] = 0;
        }
    }
}

int main()
{
    cin >> N;
    wayCount(0);
    cout << cnt << endl;
}
