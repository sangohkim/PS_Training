// N과 M 시리즈는 재귀함수를 이용한 방식으로 해결해 보았다
// 오답 원인: 처음에는 M=2인 경우에 대해서만 생각하다가 일반화된 조건문을 적지 못하였다.
// 중복 여부를 구해주는 함수를 설계하여 해결하였다.
// 다른 코드를 보니 DFS 등의 그래프 탐색을 이용하여 그냥 재귀를 이용한 방식보다 더 빠르게 해결한 풀이도 있었다.
// 나중에 해봐야 겠다.

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int N, M;
vector<int> vint;

void Show()
{
    for (auto x : vint)
        cout << x << " ";
    cout << endl;
}

bool isIncluded(int n)
{
    for (int i = 0; i < vint.size(); i++)
        if (vint[i] == n)
            return true;
    return false;
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
        if (!vint.empty() && isIncluded(i))
            continue;
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
