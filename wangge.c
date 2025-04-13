#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) {
    return (*(long long*)a - *(long long*)b);
}
// 二分查找：找到最后一个 <= limit 的元素下标
int func(long long a[], int n, long long limit) {
    int left = 0, right = n - 1, ans = n;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] <= limit) {
            ans = mid; // 找到一个符合条件的
            left = mid + 1; // 尝试找更大的
        } else {
            right = mid - 1 ; // 向左继续查找
        }
    }
    return ans;
}
int main() {
    int T;
    scanf("%d", &T); 
     
    while (T--) {
        int n, c;
        scanf("%d %d", &n, &c); 
         
        long long a[n];
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]); 
        }
        qsort(a, n,8, cmp);
        int min = n; // 初始化最少移除的元素个数为 n
        // 假设 a[i] 是最小值，计算满足条件的元素
        for (int i = 0; i < n; i++) {
            long long limit = c * a[i];
            // 二分查找找到满足 a[j] <= limit 的最大下标 j
            int pos = func(a, n, limit);
             
            // i 之前的元素都需要移除，pos 后的元素也需要移除
            int res = i + (n - 1 - pos);
            if (res < min) {
                min = res;
            }
        }
         
        printf("%d\n",min); 
    }
}