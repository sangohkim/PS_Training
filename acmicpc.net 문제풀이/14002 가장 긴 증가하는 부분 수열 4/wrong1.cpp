// 이 문제를 통해서 내가 이분탐색을 이용한 LIS탐색에 대해서 가지고 있었던 오개념을 해결할 수 있었다.
// 일단 내가 가지고 있었던 오개념은
// 아래의 코드를 통해 이루어진 이분탐색으로 구해진 벡터는 그 크기가 LIS의 크기와 동일한 것일 뿐
// 원소는 실제 답이 될 수 있는 LIS의 원소와 아아아아아아아아아아아무 관계가 없다!!!!!!
// ex) 입력이 아래와 같은 경우
// 7
// 10 100 50 20 30 15 20
// 아래 코드로 구한 벡터: 10 15 20
// 가 되는데 이는 원래 배열에서의 순서가 뒤바뀐 것이므로 답일 될 수 없다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N, nums[1000];
vector<int> vres;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    for (int i = 0; i < N; i++)
    {
        if (vres.empty() || vres.back() < nums[i])
            vres.push_back(nums[i]);
        else
            *(lower_bound(vres.begin(), vres.end(), nums[i])) = nums[i];
    }
    cout << vres.size() << endl;
    for (auto n : vres) cout << n << " ";
}
