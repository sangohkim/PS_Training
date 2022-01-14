// 분할정복을 이용한 거듭제곱, 페르마 소정리를 이용한 모듈러 연산 등 다양한
// 프로그래밍 기법 및 정수론적인 개념에 대해서 알게 되고 정리할 수 있었던 문제인 것 같다.
// 특히 분모, 분자에 모듈러 연산을 적용해야 하는 경우에는 페르마의 소정리를 떠올려보는 것을 명심해야 겠다.
#include <bits/stdc++.h>
#define P 1000000007
using namespace std;
typedef long long ll;
int N, K;
ll factorial(int n)
{
	ll res = 1;
	for (int i = 2; i <= n; i++)
	{
		res *= i;
		res %= P;
	}
	return res;
}
ll mypow(ll base, ll exponent)
{
	if (exponent == 1)
		return base;
	ll half = mypow(base, exponent / 2) % P;
	ll res = ((half % P) * (half % P)) % P;
	if (exponent % 2)
	{
		res *= base;
		res %= P;
	}
	return res;
}
int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> N >> K;
	ll a = factorial(N) % P, b = ((factorial(K) % P) * (factorial(N - K) % P)) % P;
	cout << (a * (mypow(b, P - 2) % P)) % P;
}
