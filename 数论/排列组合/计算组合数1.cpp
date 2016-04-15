/*============================================================================
* Title : 计算组合数1
* Author: Rainboy
* Time  : 2016-04-15 15:46
* update: 2016-04-15 15:46
* © Copyright 2016 Rainboy. All Rights Reserved.
*=============================================================================*/


/*
  原理：Cnm = C(n-1)(m-1) + C(n-1)m
  Cn0 = Cnn =1
*/
#include <cstdio>
#include <cstring>

int c[1001][1001];



void getC(int n){
    memset(c,0,sizeof(c));
    int i,j;
    for(i=0;i<=n;i++){
        c[i][0]=1;
        for(j=1;j<=i;j++) //这里一定从1开始
            c[i][j]=c[i-1][j-1] + c[i-1][j];
    }
}

int main(){
    int n =10;
    getC(n);

    /* 输出 */
    int i,j;
    for(i=0;i<=n;i++){
        printf("%d ",c[i][0]);;
        for(j=1;j<=i;j++)
            printf("%d ",c[i][j]);
        printf("\n");
    }


    return 0;
}
