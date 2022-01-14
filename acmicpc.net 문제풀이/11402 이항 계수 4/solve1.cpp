// 뤼카의 정리와 다른 문제에서 사용했던 페르마의 소정리, 다이나믹 프로그래밍을 이용해서
// 해결할 수 있었던 문제
#include <bits/stdc++.h>
#define LEN 2000
using namespace std;
typedef long long ll;
ll N, K, M, tot = 1;
ll cache[LEN][LEN];
ll mypow(ll base, ll exponent)
{
	if (exponent == 1)
		return base;
	ll half = mypow(base, exponent / 2) % M;
	ll res = ((half % M) * (half % M)) % M;
	if (exponent % 2)
	{
		res *= base;
		res %= M;
	}
	return res;
}
ll factorial(ll n)
{
	ll res = 1;
	for (ll i = 2; i <= n; i++)
	{
		res *= i;
		res %= M;
	}
	return res;
}
ll combination(ll n, ll k)
{
	if (n < k)
		return 0;
    if (k == 1)
        return n;
    else if (k == n || k == 0)
        return 1;
    else if (cache[n][k] != -1)
        return cache[n][k];
    else
        return cache[n][k] = (combination(n - 1, k) + combination(n - 1, k - 1)) % M;
	ll a = factorial(n) % M, b = ((factorial(k) % M) * (factorial(n - k) % M)) % M;
	ll res = (a * mypow(b, M - 2)) % M;
	return res;
}
void solve()
{
    fill(&cache[0][0], &cache[0][0] + LEN * LEN, -1);
	ll tmp_n, tmp_k;
	while (N || K)
	{
		tmp_n = N % M;
		tmp_k = K % M;
		tot *= combination(tmp_n, tmp_k) % M;
		tot %= M;
		N /= M;
		K /= M;
	}
}
int main()
{
	cin >> N >> K >> M;
	solve();
	cout << tot << '\n';
}
