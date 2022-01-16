// 그냥 브루트포싱했는데 더 멋진 그리디 방법이 있었다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N, mxres = INT_MIN;
int alpha_to_num[26], isExist[26], isUsed[10];
vector<int> valphas;
string words[10];
void input()
{
    (cin >> N).get(); // cin은 개행을 스트림에 남겨둔다
    for (int i = 0; i < N; i++)
    {
        getline(cin, words[i]);
        for (int j = 0; j < words[i].size(); j++)
            isExist[words[i][j] - 'A'] = 1;
    }
    for (int i = 0; i < 26; i++)
        if (isExist[i])
            valphas.push_back(i);
}
int getNum()
{
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        string word = words[i];
        for (int j = word.size() - 1, k = 1; j >= 0; j--, k *= 10)
        {
            res += (alpha_to_num[word[j] - 'A'] * k);
        }
    }
    return res;
}
void num_combination(int cur_idx)
{
    if (cur_idx == valphas.size())
    {
        mxres = max(mxres, getNum());
        return;
    }
    for (int num = 9 - valphas.size() + 1; num <= 9; num++)
    {
        if (!isUsed[num])
        {
            isUsed[num] = 1;
            alpha_to_num[valphas[cur_idx]] = num;
            num_combination(cur_idx + 1);
            alpha_to_num[valphas[cur_idx]] = -1;
            isUsed[num] = 0;
        }
    }
}
void solve()
{
    input();
    fill(&alpha_to_num[0], &alpha_to_num[0] + 26, -1);
    num_combination(0);
    cout << mxres << endl;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}
