#include<stdio.h>
#include<string.h>
int my_strcmp(char *a,char *b,int k){
    int i;
    for(i=0;i<k;i++){
        if(*(a+i)!=*(b+i)){
            return 0;
        }
    }
    return 1;
}
int main(){
    int T,i,j;
    scanf("%d",&T);
    while(T--){
        char s[1100];
        scanf("%s",s);
        int len=strlen(s);
        int k=len/2;
        int cnt=1;
        while(k){
            for(i=0;i<len-k;i+=k){
                 int flag=0;
                 for(j=i+k;j<len;j+=k){
                    if(my_strcmp(&s[i],&s[j],k)){
                        flag=1;
                        break;
                    }
                 }
                 if(!flag){
                    cnt++;
                    flag=0;
                }
            }
            cnt++;
            k/=2;
        }
        printf("%d\n",cnt);
    }
    return 0;
}