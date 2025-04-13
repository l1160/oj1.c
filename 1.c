#include <stdio.h>
#include <stdlib.h>
 
typedef long long ll;
 
#define MAXN 1000
 
int a[MAXN];
int b[MAXN];
 
int check(int n, ll k, ll mid) {
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        ll temp = a[i] * mid;
        if (temp > b[i]) {
            cnt += temp - b[i];
            if (cnt > k) {
                return 0;
            }
        }
    }
    return 1;
}
 
void solve(int n, ll k) {
    ll left = 0, right = 2000000000;
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (check(n, k, mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("%lld\n", right); // 输出 right 而不是 left
}
 
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        ll k;
        scanf("%d %lld", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
        solve(n, k);
    }
    return 0;
}