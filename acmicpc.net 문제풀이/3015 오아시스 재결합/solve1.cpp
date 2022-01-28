// pair를 사용하자는 생각을 하지 못했었다.
// 처음에는 겹치는 개수를 세는 변수를 만들려고 했는데 그건 불가능(나보다 작은걸 지웠을 때 나오는 겹치는 개수는 저장 불가능해서)
// 이럴 땐 배열대신 pair도 좋은 방법이 된다는걸 기억해야 겠다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N;
void solve()
{
    cin >> N;
    int num;
    long long cnt = 0, scnt = 1;
    stack<pair<int, int>> stk;
    for (int i = 1; i <= N; i++)
    {
        cin >> num;
        scnt = 0;
        while (!stk.empty() && stk.top().first < num)
        {
            cnt++;
            stk.pop();
        }
        if (!stk.empty())
        {
            if (stk.top().first == num)
            {
                scnt += stk.top().second;
                cnt += stk.top().second;
                if (stk.size() > stk.top().second)
                    cnt++;
            }
            else
                cnt++;
        }
        stk.push(make_pair(num, scnt + 1));
    }
    cout << cnt << endl;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
