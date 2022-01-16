// 처음부터 접근방식은 맞았는데
// cnt_ch가 K-5, valpha.size()의 대소 관계에 따라 결정되어야 한다는 걸 잊었음
// 만약에 valpha.size()가 K-5보다 작게되면 cnt_ch가 절대 K-5가 될 수 없다는 문제가 있었다
// 기저 조건도 꼼꼼히 봐야 
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N, K, mxread;
int isChoosed[26];
string words[50];
int isNeedTeach[26];
vector<char> valpha;
void input()
{
    (cin >> N >> K).get();
    for (int i = 0; i < N; i++)
        getline(cin, words[i]);
}
int cntReadable()
{
    int res = 0;
    for (int wordidx = 0; wordidx < N; wordidx++)
    {
        bool readable = true;
        for (int chidx = 4; chidx < words[wordidx].size() - 4; chidx++)
        {
            if (!isChoosed[words[wordidx][chidx] - 'a'])
            {
                readable = false;
                break;
            }
        }
        if (readable) res++;
    }
    return res;
}
void choose(int startidx, int cnt_ch)
{
    if (cnt_ch == min(K - 5, (int)valpha.size()))
    {
        mxread = max(mxread, cntReadable());
        return;
    }
    for (int idx = startidx; idx < valpha.size(); idx++)
    {
        if (!isChoosed[valpha[idx] - 'a'])
        {
            isChoosed[valpha[idx] - 'a'] = 1;
            choose(idx, cnt_ch + 1);
            isChoosed[valpha[idx] - 'a'] = 0;
        }
    }
}
void solve()
{
    input();
    if (K < 5)
    {
        mxread = 0;
        return;
    }
    string testStr = "antic";
    for (int i = 0; i < 5; i++)
        isChoosed[testStr[i] - 'a'] = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < words[i].size(); j++)
            if (testStr.find(words[i][j]) == string::npos)
            {
                isNeedTeach[words[i][j] - 'a'] = 1;
            }
    }
    for (int i = 0; i < 26; i++)
        if (isNeedTeach[i])
            valpha.push_back(char(i + 'a'));
    choose(0, 0);
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    cout << mxread << endl;
}
