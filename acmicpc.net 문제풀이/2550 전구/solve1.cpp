// 이 문제를 해결할 때 가장 중요한 것이 일단 LIS를 응용해야 한다는 생각을 하는 것
// 그리고 LIS 결과와 출력해야하는 결과가 서로 다르기 때문에 집중해야 하는것(내가 이것때문에 계속 틀렸음)
// 시간을 조금 줄이기 위해서 배열을 여러개 선언하였다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N;
int input_switch[10000], switch_idx[10000], bulbs_switch[10000];
int cache[10000], cache2[10000];
vector<int> vres;
int getLIS(int start_idx)
{
    int& ret = cache[start_idx];
    if (ret != -1)
        return ret;
    ret = 1;
    for (int i = start_idx + 1; i <= N; i++)
    {
        if (bulbs_switch[start_idx] < bulbs_switch[i])
        {
            int tmp = getLIS(i) + 1;
            if (ret < tmp)
            {
                ret = tmp;
                cache2[start_idx] = i;
            }
        }
    }
    return ret;
}
void input()
{
    int tmp;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> tmp;
        input_switch[i] = tmp;
        switch_idx[tmp] = i;
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> tmp;
        bulbs_switch[i] = switch_idx[tmp];
    }
}
void solve()
{
    input();

    int resLen = 0, mxidx = -1, idx;
    fill(&cache[0], &cache[0] + 10000, -1);
    for (int i = 1; i <= N; i++)
    {
        int tmpLen = getLIS(i);
        if (resLen < tmpLen)
        {
            resLen = tmpLen;
            mxidx = i;
        }
    }
    idx = mxidx;
    cout << resLen << endl;
    while (resLen)
    {
        vres.push_back(input_switch[bulbs_switch[idx]]);
        idx = cache2[idx];
        resLen--;
    }
    sort(vres.begin(), vres.end());
    for (auto n : vres)
        cout << n << " ";
    cout << endl;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
