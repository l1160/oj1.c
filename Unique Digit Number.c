#include<stdio.h>
typedef long long ll;
int book[15]={0};
ll num[8877692];
int cnt=1;
ll ans;
void dfs(int n,int m,ll ans){
    int i;
    if(n==m-1){
        num[cnt++]=ans;
        return ;
    }
    for(i=0;i<10;i++){
        if(i==0&&m==1&&n!=1){
            continue;
        }
        if(!book[i]){
            book[i]=1;
            dfs(n,m+1,ans*10+i);
            book[i]=0;
        }
    }
}
int main(){
    int i;
    
    for(i=1;i<=10;i++){
        dfs(i,1,0);
    }
    int t;
    while(scanf("%d",&t)!=EOF){
        printf("%lld\n",num[t]);
    }
    return 0;
}