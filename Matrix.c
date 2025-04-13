#include<stdio.h>
#include<string.h>

int main(){
    int n,m;
    char zbm[10];
    int i,j,t;
    int Matrix[13][13];
    while(scanf("%s",zbm)!=EOF){
    
        if(zbm[0]=='I'&&zbm[1]=='N'){
            //初始化n*m的矩阵
            //从1开始的！
            scanf("%d %d",&n,&m);
             t=1;
            for(i=1;i<=n;i++){
                for(j=1;j<=m;j++){
                    Matrix[i][j]=t;
                    t++;
                }
            }
        }
        else if(zbm[0]=='S'&&zbm[1]=='R'){
            int x,y;
            scanf("%d %d",&x,&y);
            //转换x和y行
            for(i=1;i<=m;i++){
                t=0;
                t=Matrix[x][i];
                Matrix[x][i]=Matrix[y][i];
                Matrix[y][i]=t;
            }
        }else if(zbm[0]=='S'&&zbm[1]=='C'){
            int x,y;
            scanf("%d %d",&x,&y);
            //交换x，y列
            for(i=1;i<=n;i++){
                 t=0;
                t=Matrix[i][x];
                Matrix[i][x]=Matrix[i][y];
                Matrix[i][y]=t;
            }
        }else if(zbm[0]=='T'&&zbm[1]=='R'){
            int temp[13][13];
            for(i=1;i<=n;i++){
                for(j=1;j<=m;j++){
                    temp[j][i]=Matrix[i][j];
                //    Matrix[i][j]=Matrix[j][i];
                //    Matrix[j][i]=t;
                }
            }
            
            for(i=1;i<=n;i++){
                for(j=1;j<=m;j++){
                    Matrix[j][i]=temp[j][i];
                }
            }
            t=n;
            n=m;
            m=t;
        }else if(zbm[0]=='F'&&zbm[1]=='C'){
            for(i=1;i<=n;i++){
                for(j=1;j<=m/2;j++){
                     t=Matrix[i][j];
                    Matrix[i][j]=Matrix[i][m-j+1];
                    Matrix[i][m-j+1]=t;
                }
            }
        }else if(zbm[0]=='F'&&zbm[1]=='R'){
            for(i=1;i<=n/2;i++){
                for(j=1;j<=m;j++){
                     t=Matrix[i][j];
                    Matrix[i][j]=Matrix[n-i+1][j];
                    Matrix[n-i+1][j]=t;
                }
            }
        }else if(zbm[0]=='P'&&zbm[1]=='R'){
            for(i=1;i<=n;i++){
                for(j=1;j<=m;j++){
                    printf("%d",Matrix[i][j]);
                    if(j!=m){
                        printf(" ");
                    }
                }
                printf("\n");
            }
            printf("\n");
        }
    }
    return 0;
}