// map을 사용해서 강의의 시작시간과 마치는 시각을 각각 key와 value로 할려고 했다.
// 근데 키만 같고 그 값이 다른 경우도 있어서 그 부분은 우선순위 큐를 적용하여 해결하였다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int> Pair;
int N;
void solve()
{
    cin >> N;
    map<int, priority_queue<int, vector<int>, greater<int>>> m;
    int s, t, cnt = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> s >> t;
        m[s].push(t);
    }
    Pair tmp = make_pair(m.begin()->first, m.begin()->second.top());
    m[tmp.first].pop();
    if (m[tmp.first].empty()) m.erase(tmp.first);
    while (!m.empty())
    {
        auto iter = m.lower_bound(tmp.second);
        if (iter == m.end())
        {
            cnt++;
            if (m.empty())
            {
                cout << cnt << endl;
                return;
            }
            tmp = make_pair(m.begin()->first, m.begin()->second.top());
            m[tmp.first].pop();
            if (m[tmp.first].empty()) m.erase(tmp.first);
            continue;
        }
        tmp = make_pair(iter->first, iter->second.top());
        m[tmp.first].pop();
        if (m[tmp.first].empty()) m.erase(tmp.first);
    }
    cout << cnt + 1 << endl;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
