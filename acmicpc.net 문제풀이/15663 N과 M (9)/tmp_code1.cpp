// 대체 어디가 틀렸는지 모르겠다!!!!!
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int N, M;
vector<int> vint;
vector<int> vnums;  // 입력한 수들의 중복을 제거하고 정렬한 배열
vector<int> vnums_ori;

void showV()
{
    for (auto x : vint) cout << x << " ";
    cout << endl;
}

bool isOkay(int val)
{
    if (vint.empty() || vint.back() < val) return true;
    if (vint.back() == val && count(vint.begin(), vint.end(), val) < count(vnums_ori.begin(), vnums_ori.end(), val)) return true;
    return false;
}

void input()
{
    int tmp;
    set<int> stmp;
    (cin >> N >> M).get();
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        stmp.insert(tmp);
        vnums_ori.push_back(tmp);
    }
    for (auto x = stmp.begin(); x != stmp.end(); x++)
        vnums.push_back(*x);
    sort(vnums_ori.begin(), vnums_ori.end());
}

void solve()
{
    if (vint.size() == M)
    {
        showV();
        return;
    }

    for (int nidx = 0; nidx < vnums.size(); nidx++)
    {
        if (isOkay(vnums[nidx]))
        {
            vint.push_back(vnums[nidx]);
            solve();
            vint.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
}
