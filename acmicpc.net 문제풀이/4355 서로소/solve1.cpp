// N의 소인수 중에 루트N보다 큰 건 많아야 한개다.
// pf) 두 개 존재한다고 가정
// a = N^0.5 + k1, b = N^0.5 + k2 (k1, k2양수)
// N은 a * b보다 큼
// a * b >= N 즉 모순
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n;
void solve()
{
    cin >> n;
    while (n)
    {
        int res = n;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i) continue;
            res -= res / i;
            while (n % i == 0) n /= i;
        }
        if (n > 1) res -= res / n;
        cout << res << endl;
        cin >> n;
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
