// 이거 3번 틀리고 맞았는데 처음에는 부호를 +, -만 생각하다가 0이 있는거 빼먹었었다.
// 그리고 두 번째, 세 번째는 58번줄때문에 틀렸던 거였는데
// lower == solutions는 항상 참이다. 그러나 lower == solutions + first_plus_idx하니까 제대로 검사가 되었다.
#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(false)
#define endl '\n'
using namespace std;
typedef long long ll;
int N, first_plus_idx;
ll sol1, sol2, plus_min, minus_min, diff = LLONG_MAX;
ll solutions[100000];
bool isAllPlus = true, isAllMinus = true;
void set_min(ll s1, ll s2)
{
    if (abs(s1 + s2) < diff)
    {
        sol1 = (s1 < s2 ? s1 : s2);
        sol2 = (s1 > s2 ? s1 : s2);
        diff = ll(abs(sol1 + sol2));
    }
}
void input()
{
    for (int i = 0; i < N; i++)
    {
        cin >> solutions[i];
        if (solutions[i] > 0) isAllMinus = false;
        if (solutions[i] < 0) isAllPlus = false;
    }
    sort(solutions, solutions + N);
    for (int i = 0; i < N; i++)
        if (i != 0 && solutions[i - 1] < 0 && solutions[i] >= 0)
            first_plus_idx = i;
}
void solve()
{
    // 부호가 모두 동일한 경우
    if (isAllPlus)
    {
        cout << solutions[0] << " " << solutions[1] << endl;
        return;
    }
    if (isAllMinus)
    {
        cout << solutions[N - 2] << " " << solutions[N - 1];
        return;
    }

    // 부호가 모두 동일하지 않은 경우
    // +, -가 섞여있는 최솟값이랑 마지막에 이 두 값이랑 비교하기
    for (int i = 0; i < first_plus_idx; i++)
    {
        auto lower = lower_bound(solutions + first_plus_idx, solutions + N, ll(abs(solutions[i])));
        if (lower == solutions + N)  // 현재 음수인 이 특성값이 절댓값을 씌우면 최대가 됨
        {
            set_min(solutions[i], solutions[N - 1]);
            continue;
        }
        if (lower != solutions + first_plus_idx)
            set_min(solutions[i], *(lower - 1));
        set_min(solutions[i], *lower);
    }
    if (first_plus_idx >= 2)
        set_min(solutions[first_plus_idx - 2], solutions[first_plus_idx - 1]);
    if (first_plus_idx <= N - 2)
        set_min(solutions[first_plus_idx], solutions[first_plus_idx + 1]);

    cout << sol1 << " " << sol2 << endl;
}
int main()
{
    cin >> N;
    input();
    solve();
}
