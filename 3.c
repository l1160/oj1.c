#include<stdio.h>
#include<string.h>

int a[100010],b[100010];
int main(){
    int T,n,m;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int i,t;
    //    int a[n];
        for(i=0;i<n;i++){
            scanf("%d",&t);
            a[t]++;
        }
        scanf("%d",&m);
    //    int b[m];
        for(i=0;i<m;i++){
            scanf("%d",&t);
            b[t]++;
        }
        int cnt=0;
        for(i=0;i<=100000;i++){
            if((a[i]>1&&b[i]==0)){
                cnt++;
            }
        }
        int cnt2=0;
        for(i=0;i<=100000&&cnt!=0;i++){
            if(a[i]==0&&b[i]>1){
                cnt2++;
                cnt--;
            }
        }
        printf("%d\n",cnt2);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
    }
    return 0;
}