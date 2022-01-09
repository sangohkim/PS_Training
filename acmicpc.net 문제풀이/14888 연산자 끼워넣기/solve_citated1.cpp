// tsh0003 님의 코드
// 이 코드를 보니 너무 N과 M문제처럼 해결할려고 했었던 것 같기도 하다.
// 이 분의 코드는 내 방식과 다르게 애초에 연산자가 중복되는 경우 자체가 없다.
// 조건문으로 음수가 되는 경우는 자동으로 걸러내는 것도 좋은 것 같다.

#include <cstdio>
using namespace std;
int n;
int a[11], op[4];
int mx = -1e9, mn = 1e9;

void solve(int index, int ans, int add, int sub, int mul, int div) {
    if (index >= n) {
        if (ans > mx) mx = ans;
        if (ans < mn) mn = ans;
        return;
    }
    if (add) solve(index+1, ans+a[index], add-1, sub, mul, div);
    if (sub) solve(index+1, ans-a[index], add, sub-1, mul, div);
    if (mul) solve(index+1, ans*a[index], add, sub, mul-1, div);
    if (div) solve(index+1, ans/a[index], add, sub, mul, div-1);
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    for (int i=0; i<4; i++) scanf("%d", &op[i]);
    solve(1, a[0], op[0], op[1], op[2], op[3]);
    printf("%d\n%d\n", mx, mn);
    return 0;
}
