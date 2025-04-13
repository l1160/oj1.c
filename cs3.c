#include<stdio.h>
typedef unsigned long long ull;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int num[1000];
        int cnt=0,i,ans=0;
        ull n;
        scanf("%llu",&n);
        // while(n){
        //     num[cnt++]=n%2;
        //     n/=2;
        // }
        for(i=0;n;i++,n>>=1){
            num[i]=(int) n&1;
        }
        for(i=2;i<cnt;i++){
            if(num[i]==1&&num[i-1]==0&&num[i-2]==1){
                ans++;
                num[i]=0;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}