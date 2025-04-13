#include<stdio.h>
#define N 100010
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[N]={0};
    long long ans[N]={0};
    long long num[N]={0};
    int i,l,r,d;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        num[i]=a[i]-a[i-1];
    }
    while(m--){
        scanf("%d%d%d",&l,&r,&d);
        num[l]+=d;
        num[r+1]-=d;
    }
    for(i=1;i<=n;i++){
        a[i]=a[i-1]+num[i];
    }
    for(i=1;i<=n;i++){
        ans[i]=a[i]+ans[i-1];
    }
    for(i=1;i<n;i++){
        printf("%lld ",ans[i]);
    }
    printf("%lld\n",ans[n]);
    return 0;
}


// #include <bits/stdc++.h>
 
// using ll = long long;
// const int N = 100010;
// ll n;
// int a[N];
// int main() {
//     std::cin >> n;
//     for (int i = 1; i <= n ; i ++) {
//         std::cin >> a[i];
//     }
 
//     std::cout << (n - 1) * n / 2 << '\n';
//     return 0;
// }