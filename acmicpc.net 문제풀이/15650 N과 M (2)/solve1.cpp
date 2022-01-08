#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int N, M;
vector<int> vint;

void Show()
{
    for (auto n : vint) cout << n << " ";
    cout << endl;
}

void solve()
{
    if (vint.size() == M)
    {
        Show();
        return;
    }
    int smallest = (vint.empty() ? 1 : vint.back() + 1);
    for (int n = smallest; n <= N; n++)
    {
        vint.push_back(n);
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
