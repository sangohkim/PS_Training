// 처음에는 문제 제목인 CCW에 관해서는 별로 관심이 없었는데
// 알고보니 기하학에서 중요한 알고리즘인 Counter Clock Wise라는 것이다.
// 쉽게는 신발끈 공식(즉 벡터의 외적)을 통해서 시계방향, 시계반대방향인지를 판단할 수 있는 방식이다.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x1, y1, x2, y2, x3, y3;
    
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    int vx1 = x2 - x1, vx2 = x3 - x1, vy1 = y2 - y1, vy2 = y3 - y1;
    int det = vx1 * vy2 - vx2 * vy1;
    if (det < 0)
        cout << -1;
    else if (det > 0)
        cout << 1;
    else
        cout << 0;
}
