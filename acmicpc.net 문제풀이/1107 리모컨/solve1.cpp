// 나는 아직 예외나 모든 경우를 생각하는데에 미숙한듯....
// 오늘 배운 것
// 0은 자릿수 구할 때 따로 예외 처리를 해주어야 한다.
#include <bits/stdc++.h>
#define endl '\n'
#define MAX_CHANNEL 500000 * 2
#define VERYBIG 987654321
using namespace std;
int TARGET, M, isBroken[10], min_click;
int getDigit(int channel)
{
    if (channel == 0)
        return (isBroken[0] ? VERYBIG : 1);    // 중요한 라인
    int res = 0;
    while (channel)
    {
        if (isBroken[channel % 10])
            return VERYBIG;
        res++;
        channel /= 10;
    }
    return res;
}
void clickCount()
{
    for (int n = 0; n <= MAX_CHANNEL; n++)
    {
        min_click = min(min_click, getDigit(n) + abs(TARGET - n));
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> TARGET;
    cin >> M;
    int broken_button;
    for (int i = 0; i < M; i++)
    {
        cin >> broken_button;
        isBroken[broken_button] = 1;
    }
    min_click = abs(TARGET - 100);
    if (min_click != 0) 
        clickCount();
    cout << min_click << endl;
}
