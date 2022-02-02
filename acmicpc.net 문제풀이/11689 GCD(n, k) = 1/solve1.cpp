// 가장 큰 소인수가 N^0.5보다 크다고 하더라도
// 두번째로 큰 소인수는 N^0.5보다 작다고 하는데 항상 그런건가
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll n;
void solve()
{
    cin >> n;
    ll ans = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i) continue;
        ans = ans - ans / i;
        while (n % i == 0) n /= i;
    }
    if (n > 1) ans = ans - ans / n;
    cout << ans << endl;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
