// 이전에 풀었던 N과 M문제와 유사한 방식으로 접근하였다.
// 처음에는 중복되는 것을 그냥 놔두었는데 그러면 시간초과가 났다.(계산결과값을 테스트코드삽입으로 출력해보니 중복되는 계산이 많았다.)
// 그래서 이전 값을 저장하는 변수를 설정하여 중복된 계산 수를 줄여서 시간 내에 통과되었다.
// 중간에 삽입한 테스트코드를 깜빡하고 제거하지 않아 출력초과가 한 번 떴는데 다음에는 잘 확인해야 겠다.

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int N;
int mx_res = INT_MIN, mn_res = INT_MAX;
vector<int> vnums;
vector<int> vops;
vector<int> vcombs;

void addOperator(int opNum, int cnt)
{
    for (int i = 1; i <= cnt; i++)
        vops.push_back(opNum);
}

void input()
{
    int tmp;
    (cin >> N).get();
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        vnums.push_back(tmp);
    }
    cin.get();
    for (int i = 0; i < 4; i++)
    {
        cin >> tmp;
        if (tmp == 0)
            continue;
        else
            addOperator(i, tmp);
    }
}

void cal_judge()
{
    int res = vnums.front();

    for (int i = 0; i < vcombs.size(); i++)
    {
        switch (vcombs[i])
        {
        case 0:
            res += vnums[i + 1];
            break;
        case 1:
            res -= vnums[i + 1];
            break;
        case 2:
            res *= vnums[i + 1];
            break;
        case 3:
            res /= vnums[i + 1];
            break;
        }
    }
    if (mx_res < res) mx_res = res;
    if (mn_res > res) mn_res = res;
}

bool isOkay(int opNum)
{
    if (vops.empty() || count(vcombs.begin(), vcombs.end(), opNum) < count(vops.begin(), vops.end(), opNum))
        return true;
    return false;
}

void solve()
{
    if (vcombs.size() == vops.size())
    {
        cal_judge();
        return;
    }

    int prev = -1;
    for (int i = 0; i < vops.size(); i++)
    {
        if (isOkay(vops[i]) && vops[i] != prev)
        {
            vcombs.push_back(vops[i]);
            solve();
            vcombs.pop_back();
            prev = vops[i];
        }
        else
            continue;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();

    cout << mx_res << endl << mn_res << endl;
}
