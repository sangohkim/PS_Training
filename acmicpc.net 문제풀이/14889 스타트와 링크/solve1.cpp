// 모든 경우를 잘 고려하는 것까지는 처음부터 잘 구현하였으나
// 겹치는 경우를 제외하는 것을 처음에는 잊어서 계속 시간초과가 났다.
// 앞으로 브루트포스, 백트래킹 문제에서 코드에 큰 이상이 없는데도 시간초과가 나면
// 같은 경우를 여러번 세는 것은 아닌지 꼭 확인해야 겠다.
// 벡터를 이용해서 오름차순으로 팀을 선발함으로서 문제를 해결할 수 있었다.
#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.tie(0)->sync_with_stdio(false)
using namespace std;

int N, mn_diff = INT_MAX;
int arrPower[20][20];
int isStartTeam[20];
vector<int> vStart;

int calDiff()
{
    int start = 0, link = 0;
    for (int i = 0; i < 20; i++)
    {
        if (isStartTeam[i])
        {
            for (int j = 0; j < 20; j++)
                if (i != j && isStartTeam[j])
                    start += (arrPower[i][j]);
        }
        else
        {
            for (int j = 0; j < 20; j++)
                if (i != j && !isStartTeam[j])
                    link += arrPower[i][j];
        }
    }
    return (int)abs(start - link);
}

void getDiff()
{
    if (vStart.size() == N / 2)
    {
        mn_diff = min(mn_diff, calDiff());
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (!isStartTeam[i] && (vStart.empty() || vStart.back() < i))
        {
            isStartTeam[i] = 1;
            vStart.push_back(i);
            getDiff();
            vStart.pop_back();
            isStartTeam[i] = 0;
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> arrPower[i][j];
        }
    getDiff();
    cout << mn_diff << endl;
}
