#include<stdio.h>
#include<string.h>
typedef long long ll;
int my_max(int a,int b){
    return a>b?a:b;
}
int main(){
    int n;
    char s[10010];
    int num[10010];
    while(scanf("%s %d",s,&n)!=EOF){
        int max=-1,cnt=0;
        ll ans=0;
        int len=strlen(s);
        for(int i=0;i<len;i++){
            if(s[i]<='9'){
                num[i]=s[i]-'0';
            }else{
                num[i]=s[i]-'A'+10;
            }
            if(num[i]>max){
                max=num[i];
            }
        }
        cnt=max+1;
        int i;
        for(i=max+1;i<=16;i++){
        //    int p=i;
            cnt=i;
            ans=0;
            for(int j=0;j<len;j++){
                ans=num[j]+ans*i;
            }
            if(ans==n){
                break;
            }
        }
        if(i<=16){
            printf("%d\n",i);
        }else{
            printf("Impossible\n");
        }
    }

    return 0;
}
// 
