// 일단 외적을 쓰자는 생각은 들었다.
// 근데 처음에는 오목다각형인 경우를 고려하지 않았다.
// 오목다각형인 경우에는 처음에는 CCW를 써서 오목인 부분을 찾아낸 다음 어쩌고 저쩌고 할 생각이었지만
// 그냥 외적한 결과값을 절댓값처리하지 않고 더하게 되면 알아서 소거된다는 것을 깨달은 후 문제를 쉽게 해결할 수 있었다.
#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.tie(0)->sync_with_stdio(false)
using namespace std;
int N;
double area;
vector<vector<int>> vxy;
double getArea(int idx1, int idx2)
{
    double vx1 = double(vxy[idx1][0] - vxy[0][0]), vy1 = double(vxy[idx1][1] - vxy[0][1]);
    double vx2 = double(vxy[idx2][0] - vxy[0][0]), vy2 = double(vxy[idx2][1] - vxy[0][1]);
    return (vx1 * vy2 - vx2 * vy1) / 2.0;
}
int main()
{
    cout << fixed;
    cout.precision(1);
    double subarea = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        vector<int> vtmp(2);
        cin >> vtmp[0] >> vtmp[1];
        vxy.push_back(vtmp);
    }
    for (int i = 1; i < N - 1; i++)
    {
        subarea += getArea(i, i + 1);
        cout << "Area: " << getArea(i, i + 1) << endl;
    }
    cout << abs(subarea);
}
