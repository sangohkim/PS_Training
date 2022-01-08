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
        if (vint.empty() || vint.back() <= i)
        {
            vint.push_back(i);
            solve();
            vint.pop_back();
        }
        else
            continue;
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
