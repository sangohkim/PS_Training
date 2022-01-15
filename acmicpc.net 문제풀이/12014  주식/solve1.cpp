#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int T, N, K;
int prices[10001];
void solve()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        vector<int> vres;
        cin >> N >> K;
        for (int i = 1; i <= N; i++)
            cin >> prices[i];
        vres.push_back(prices[1]);
        for (int i = 2; i <= N; i++)
        {
            if (vres.back() < prices[i])
                vres.push_back(prices[i]);
            else
                *(lower_bound(vres.begin(), vres.end(), prices[i])) = prices[i];
        }
        cout << "Case #" << t << endl;
        cout << ((vres.size() >= K) ? 1 : 0) << endl;  // 삼항연산자 쓸 때 괄호 안치면 뒤에 endl출력안됨
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
