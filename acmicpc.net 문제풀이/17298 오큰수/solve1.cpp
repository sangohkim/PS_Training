// 실행시간이 스택으로 최대한 줄여보았는데도 오래 걸리긴 했다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N;
int A[1000000];
int NGE[1000000];
void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
}
void solve()
{
    input();
    stack<int> mxNums;
    NGE[N - 1] = -1;
    mxNums.push(A[N - 1]);
    for (int i = N - 2; i >= 0; i--)
    {
        if (A[i] < mxNums.top())
        {
            NGE[i] = mxNums.top();
        }
        else
        {
            while (!mxNums.empty() && mxNums.top() <= A[i])
                mxNums.pop();
            if (mxNums.empty())
                NGE[i] = -1;
            else
                NGE[i] = mxNums.top();
        }
        mxNums.push(A[i]);
    }
    for (int i = 0; i < N; i++)
        cout << NGE[i] << " ";
    cout << endl;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
