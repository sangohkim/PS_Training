// 일단 완전탐색으로 먼저 구현해보았다.
// N이 적은 경우에 답은 도출되었지만
// 시간복잡도를 구해보면 가능한 경우의 수가 N^N이고 또 한 번 함수가 호출될 때마다 반복문이 하나 있어서
// O(N^(N + 1))정도로 사용 불가능이다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N, cost[1000], max_cost;
void payMax(int cur_cost, int cardcnt)
{
    if (cardcnt > N)
        return;
    if (cardcnt == N)
    {
        max_cost = max(max_cost, cur_cost);
        return;
    }
    for (int i = 0; i < N; i++)
        payMax(cur_cost + cost[i], cardcnt + 1);
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> cost[i];
    payMax(0, 0);
    cout << max_cost << endl;
}
