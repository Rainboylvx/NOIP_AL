/*============================================================================
* Title : 判断素数
* Author: Rainboy
* Time  : 2016-04-13 14:18
* update: 2016-04-13 14:18
* © Copyright 2016 Rainboy. All Rights Reserved.
*=============================================================================*/

/* 原理:
 *
 * */


#include <cstdio>
#include <cmath>    //为了使用sqrt

bool isprime(int x){
    int i,n =sqrt(x)+0.5;//sqrt(9) =2.99999
    for (i=2;i<=n;i++)
        if( x%i==0 ) return false;
    return  true;
}

int main(){
    bool s = isprime(9);
    return 0;
}




