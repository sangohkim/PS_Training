// DP로 구현하면 캐싱을 통해서 중복된 연산을 줄이고 시간 내에 해결이 가능하게 된다.
// 우선 기저 사례부터 생각하면 카드를 0개 사거나 1개사는 경우에는 최대 가격이 정해지게 된다.
// 그리고 f(N) = max(f(N - 1) + cost[1], f(N - 2) + cost[2], ... , f(0) + cost[N])이기 때문에
// 이를 함수로 구현해주면 된다.(초반에 부분문제가 cardcnt만큼의 갯수를 사는데 드는 최댓값인데 cardcnt자리에
// 계속 N을 넣어서 해결이 잘 되지 않았다)
// 이 경우 시간 복잡도를 구해보면 가능한 부분문제의 갯수 최대는 N이고 한 번 호출되었을 때 반복문의 최대도 N이다.
// 따라서 O(N^2)이 되고 N의 최댓값이 1000이기 때문에 1초 안에 해결이 가능하다고 판단할 수 있다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N, cost[1001], max_cost, cache[1001];
int payMax(int cardcnt)
{
    if (cardcnt == 0)
        return 0;
    if (cardcnt == 1)
        return cost[1];
    int& ret = cache[cardcnt];
    if (ret != -1)
        return ret;
    for (int i = 1; i <= cardcnt; i++)
        ret = max(ret, payMax(cardcnt - i) + cost[i]);
    return ret;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> cost[i];
    fill(&cache[0], &cache[0] + 1001, -1);
    cout << payMax(N) << endl;
}
