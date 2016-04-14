/*============================================================================
* Title : GCD 欧几里得算法
* Author: Rainboy
* Time  : 2016-04-13 11:21
* update: 2016-04-13 11:21
* © Copyright 2016 Rainboy. All Rights Reserved.
*=============================================================================*/

/* 
 * 有两种形式: 1.递归  2.非递归
 *  
 *
 * */

#include <cstdio>



/* 递归 */
int gcd1(int a,int b){
    if( b == 0) return a;
    return gcd1(b,a%b);
}

/* 非递归 */
int gcd2(int a,int b){
    int i;
    while(b != 0){
        i=a; a=b; b= i % b;
    }
    return a;
}


int main(){
    int x = gcd1(10,8);
    int y = gcd2(10,8);
    printf("x=%d,y=%d\n",x,y);
    return 0;
}
