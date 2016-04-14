/*============================================================================
* Title : 最小公倍数
* Author: Rainboy
* Time  : 2016-04-13 11:44
* update: 2016-04-13 11:44
* © Copyright 2016 Rainboy. All Rights Reserved.
*=============================================================================*/


/* 原理:
 *      lcm(int a,int b) * gcd(int a,int b) = a*b
 * */

int gcd(int a,int b){
    if(b == 0) return a;
    return gcd(a,a%b);
}
int lcm(int a,int b){
    return a/ gcd(a,b) *b;
}

int main(){
    int x= lcm(12,8);
    return 0;
}
