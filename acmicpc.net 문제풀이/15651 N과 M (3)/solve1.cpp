// 문제 조건을 잘못 이해해서 틀렸었다.
// 역시 문제를 잘 읽는 것이 가장 중요하다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int N, M;
vector<int> vint;

void Show()
{
    for (auto x : vint) cout << x << " ";
    cout << endl;
}

void solve()
{
    if (vint.size() == M)
    {
        Show();
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        vint.push_back(i);
        solve();
        vint.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    solve();
}
