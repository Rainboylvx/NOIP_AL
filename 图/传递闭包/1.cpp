/*-------------------------------------------------
*  Author:Rainboy
*  time : 2016-03-31 14:17
*  © Copyright 2016 Rainboy. All Rights Reserved.
*-------------------------------------------------*/

/*
 * 这个很简单
 * */

#include <cstdio>

#define N 100
bool f[N][N] = {0};


int main(){
    freopen("1.in","r",stdin);
    int n,i,j,k,t;
    scanf("%d%d",&n,&t);
    //预处理
    for(i=1;i<=t;i++){
        scanf("%d%d",&j,&k);
        f[j][k] = 1;
    }
    for(k=1;k<=t;k++)
        for(i=1;i<=t;i++)
            for(j=1;j<=t;j++){
                f[i][j] = f[i][j] || (f[i][k] && f[k][j]);
            }
    for(i=1;i<=t;i++){
        for(j=1;j<=t;j++){
         printf("%d",f[i][j]);
        }
        printf("\n");
    }
    return 0;
}

