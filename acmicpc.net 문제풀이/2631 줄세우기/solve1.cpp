// LIS를 사용하는 문제라는 것을 알게되어 잘 풀었음
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N;
int kids[200];
vector<int> vres;
void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> kids[i];
}
void solve()
{
    input();
    vres.push_back(kids[0]);
    for (int i = 1; i < N; i++)
    {
        if (vres.back() < kids[i])
            vres.push_back(kids[i]);
        else
            *(lower_bound(vres.begin(), vres.end(), kids[i])) = kids[i];
    }
    cout << N - vres.size() << endl;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
