#include<stdio.h>

typedef long long ll;
ll ans[2000]={0};
int book[100];
int cnt=0;
void init(){
    int i,j,k;
    for(i=0;i<66;i++){
        book[i]=1;
    }
    for(i=2;i<65;i++){
        for(j=2;j<=i;j++){
            book[j]=0;
            for(k=1;k<=i;k++){
                ans[cnt]=ans[cnt]*2+book[k];
            }
            cnt++;
            book[j]=1;
        }
    }
}
int main(){
    int k;
    init();
    scanf("%d",&k);
    while(k--){
        ll a,b;
        int sum=0;
        scanf("%lld %lld",&a,&b);
        for(int i=0;i<cnt;i++){
            if(ans[i]>=a&&ans[i]<=b){
                sum++;
            }
            if(ans[i]>b){
                break;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}