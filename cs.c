#include<stdio.h>

int main(){
    int n;
    int a[100010];
    while(scanf("%d",&n)!=EOF){
        int i;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        long long ans=(n-1)*3/2;
        printf("%lld\n",ans);
    }
    return 0;
}