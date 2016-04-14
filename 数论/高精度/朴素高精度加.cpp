/*============================================================================
* Title : 朴素高精度加
* Author: Rainboy
* Time  : 2016-04-13 20:48
* update: 2016-04-13 20:48
* © Copyright 2016 Rainboy. All Rights Reserved.
*=============================================================================*/

/* 算法思想:
 *          用字符串来存数字,模拟运算过程,字符串最长255
 *  
 *  原理:
 *      123
 *   +  456
 *   -------
 *      579
 *
 * */

#include <cstdio>
#include <cstring>

char s1[250],s2[250]; //存字符

int a[250]={0},b[250] ={0};
int c[250]={0};

int main(){
    int i,j;
    scanf("%s%s",s1,s2);

    /* 倒序存储 */
    i=strlen(s1);
    for(i=i-1;i>=0;i--)
        a[i]=s1[i]-'0';
    i=strlen(s2);
    for(i=i-1;i>=0;i--)
        b[i]=s2[i]-'0';

    /* 计算 */
    j= strlen(s1)>strlen(s2)?strlen(s1):strlen(s2);//最长的那个

    for(i=0;i<j;i++){
        c[i]=(a[i]+b[i])%10+c[i];
        c[i+1]=(a[i]+b[i])/10;  //进位
    }

    if(c[i+1]) i=i+1; //判断最高们进位后是否向上进位

    /*  输出 */
    for(i=j-1;i>=0;i--)
        printf("%d",c[i]);
    return 0;
}



