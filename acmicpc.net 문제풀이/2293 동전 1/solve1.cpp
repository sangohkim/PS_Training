// 계속 top-down방식으로 만들어볼려고 했는데 메모리 초과가 계속 나서 실패
// 내 생각에는 캐싱이 효율적으로 일어날만큼 중복되는 경우가 많게 설계하는데 실패한듯
// 그래서 아래의 방식대로 하면 됨
// cache[k]배열: N개 종류의 동전으로 가격k를 만드는 경우의 수
// 그래서 새로운 경우는 기존에다가 
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N, K, values[100], cache[10001];
void input()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> values[i];
    sort(values, values + N);
}
void solve()
{
    input();
    cache[0] = 1;
    for (int i = 0; i < N; i++)
        for (int j = values[i]; j <= K; j++)
        {
            cache[j] += cache[j - values[i]];
        }
    cout << cache[K] << endl;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
