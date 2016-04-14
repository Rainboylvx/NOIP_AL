/*============================================================================
* Title : 朴素高精度减法
* Author: Rainboy
* Time  : 2016-04-14 11:06
* update: 2016-04-14 11:06
* © Copyright 2016 Rainboy. All Rights Reserved.
*=============================================================================*/


/*  原是模拟减法
 *      
 *      过程:
 *        1. 读取字符串
 *        2. 保证s1>=s2 ,a=s1,b=s2
 *        3. 运算 c=a-b
 *
 *
 * */

#include <cstdio>
#include <cstring>


char s1[250],s2[250]; // 存字符串

int a[250],b[250],c[250]; //数据存储

int main(){
    /* 读取数据 */
    scanf("%s%s",s1,s2);

    /* 处理数据 */
    int la,lb,lc;
    int i,j;
    la = strlen(s1);
    lb = strlen(s2);
    
    for(i=0;i<la;i++)
        a[i] = s1[i] - '0';

    for(i=0;i<lb;i++)
        b[i] = s2[i] -'0';

    /* 默认 a - b */
    if(lb >la || (la== lb && strcmp(s1,s2)==-1)){
        printf("-");//flag;
        i=la;la=lb;lb=i; //交换
        int *c =a;a=b;b=a;//交换
    }
    jianfa();

    return 0;
}
