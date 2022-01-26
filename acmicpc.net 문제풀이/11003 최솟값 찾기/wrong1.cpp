// 내가 계산한 시간복잡도는(M은 수의 최댓값)
// O(NlgM)이었는데 시간초과가 나더라...
#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
using namespace std;
int N, L;
vector<int> vnums = { 0 };
map<int, int> m;
void solve()
{
    cin >> N >> L;
    int num, element_cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> num;
        vnums.push_back(num);
        m[num]++;
        if (i > L)
        {
            m[vnums[i - L]]--;
            if (m[vnums[i - L]] == 0)
                m.erase(vnums[i - L]);
        }
        cout << m.begin()->first << " ";
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
