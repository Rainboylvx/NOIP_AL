/*============================================================================
* Title : 朴素高精度乘法
* Author: Rainboy
* Time  : 2016-04-13 20:59
* update: 2016-04-13 20:59
* © Copyright 2016 Rainboy. All Rights Reserved.
*=============================================================================*/

/*  思想:
 *          模拟运算,a[]="123" b[] = "123"
 *          a[1]*b[1]  放在c[1+1]
 *          a[1]*b[0] 放在c[1+0]
 * */

#include <cstdio>
#include <cstring>

char s1[250],s2[250];
int a[250,b[250],c[250]={0};

int main(){
    scanf("%s%s",s1,s2);
    int i,j,k;
    i =strlen(s1);
    
    for(i=i-1;i>=0;i--)
        a[i] = s1[i]-'0';

    i=strlen(s2);
    for(i=i-1;i>=0;i--)
        b[i]=s2[i]-'0';

    k=strlen(s1)+strlen(s2);
    /* 运算 */
    for(i=0;i<strlen(s1);i++)
        for(j=0;j<strlen(s2);j++){
            c[i+j]+=a[i]*b[j];
        }

    /* 处理进位 */
    for(i=0;i<k;i++){ //不会超过k位
        c[i+1]+=c[i]/10;
        c[i]=c[i]%10;
    }

    /* 处理最高位 */
    /* n位数 * m位数 ,最多有n+m位,最少n+m-1位 */
    if(c[k-1] == 0) k--; //最高位下标k-1

    for(i=k-1;i>=0;i--)
        printf("%d",c[i]);
    return 0;
}


