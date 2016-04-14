/*============================================================================
* Title : 筛选法产生素数表
* Author: Rainboy
* Time  : 2016-04-13 14:20
* update: 2016-04-13 14:20
* © Copyright 2016 Rainboy. All Rights Reserved.
*=============================================================================*/

/*  作用:
 *  有时候为了快速判断素数,那我们自己在本地构造一个素数表,这样很快
 *
 * */

#include <cstdio>

#define N 10000
bool vis[N]={0}; //如果被筛,设为true

int primes,n=0;

void sh(){
    for(i=2;i<N;i++){
        if(!vis[i]){
            primes[n++]=i;
            for(j=i+i,j<N;j+=i) vis[j]=true;
        }
    }
}
