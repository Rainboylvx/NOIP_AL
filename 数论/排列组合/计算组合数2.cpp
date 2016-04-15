/*============================================================================
* Title : 计算组合数2
* Author: Rainboy
* Time  : 2016-04-15 15:52
* update: 2016-04-15 15:52
* © Copyright 2016 Rainboy. All Rights Reserved.
*=============================================================================*/


/* 
 *  原理:
 *  Cnm = Cn(n-m);
 *  Cn0  = cnn =1;
 *  cnm = (n-m+1)/m * cn(m-1)
 * */

#include <cstdio>

int c[1001];

//求Cnm
int getc(int n,int m){
    c[0]=1; // Cn0 = 1
    if(m > n-m) m =n-m;
    
    int i;
    for(i=1;i<=m;i++)
        c[i] = (n-i+1)*c[i-1]/i; // 先* 后/ 一定得到的是整数
    return c[m];
}

int main(){
    int n,m;
    n=5;
    m=2;
    printf("%d",getc(n,m));
    return 0;
}

