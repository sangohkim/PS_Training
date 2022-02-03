// 이 문제를 통해서 배울 수 있었던 점
// 10^9+7은 직접 칠 생각 하지말고 (long long)(1e9+7)로 하면 실수 확률 줄어든다.
// MOD로 나누면 항상 int범위에 속한다고 해도 곱하는 과정에서 int보다 큰 값이 나올 수 있으므로
// 오버플로가 발생할 수 있다는 생각이 조금이라도 든다면 무조건 long long을 쓰자
// 어떤지 감이 안잡힐때는 naive하게 출력해보자
#include <bits/stdc++.h>
#define endl '\n'
#define MOD (long long)(1e9+7)
using namespace std;
int N, M, max_nm;
vector<int> isPrime, vprimes;
void precalc()
{
    isPrime = vector<int>(max_nm + 1, 1);
    isPrime[1] = 0;
    for (int i = 2; i * i <= max_nm; i++)
    {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= max_nm; j += i) isPrime[j] = 0;
    }
    for (int i = 2; i <= max_nm; i++) if (isPrime[i]) vprimes.push_back(i);
}
long long pow_mod(int n, int k)
{
    if (k == 0) return 1;
    long long tmp = pow_mod(n, k / 2) % MOD;
    long long tmp_res = tmp * tmp;
    long long res = tmp_res % MOD;
    if (k % 2)
    {
        res *= n;
        res %= MOD;
    }
    return res;
}
void solve()
{
    cin >> N >> M;
    max_nm = max(N, M);
    precalc();
    long long res = 1;
    for (int idx = 0; idx < vprimes.size(); idx++)
    {
        int prime = vprimes[idx], cnt = 0;
        for (int i = prime; i <= max_nm; i *= prime)
            cnt += (N / i) * (M / i);
        res *= pow_mod(prime, cnt) % MOD;
        res %= MOD;
    }
    cout << res << endl;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
