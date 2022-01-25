// 우선순위 큐의 cmp 구조체로 설정할 때 기억해야 할 것
// 1. 구조체를 선언해서 ()연산자를 재정의한다.
// 2. 두 개의 인자를 받았을 때 2번째 인자의 우선순위가 큰 경우에 true를 리턴한다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N, x;
struct cmp {
    bool operator()(int a, int b)
    {
        if (abs(a) > abs(b))
            return true;
        else if (abs(a) == abs(b) && a > b)
            return true;
        else
            return false;
    }
};
void solve()
{
    cin >> N;
    priority_queue<int, vector<int>, cmp> pq;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        if (x != 0)
            pq.push(x);
        else
        {
            if (pq.empty())
                cout << 0 << endl;
            else
            {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
