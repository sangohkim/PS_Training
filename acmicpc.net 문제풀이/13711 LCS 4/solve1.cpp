// 처음에는 어떻게 풀지 막막했는데
// 전깃줄 문제와 유사하다는 것을 깨닫고 쉽게 해결할 수 있었다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N, arr1[100001], arr2[100001];
vector<int> vres;
void input()
{
    int tmp;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> tmp;
        arr1[tmp] = i;
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> tmp;
        arr2[i] = arr1[tmp];
    }
}
void solve()
{
    input();
    vres.push_back(arr2[1]);
    for (int i = 2; i <= N; i++)
    {
        if (vres.back() < arr2[i])
            vres.push_back(arr2[i]);
        else
            *(lower_bound(vres.begin(), vres.end(), arr2[i])) = arr2[i];
    }
    cout << vres.size() << endl;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
