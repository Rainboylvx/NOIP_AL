/*-------------------------------------------------
*  Author:Rainboy
*  time : 2015-12-31 17:02
*  © Copyright 2015 Rainboy. All Rights Reserved.
*-------------------------------------------------*/

/* 一句话算法：n个数 有n-1轮比较，第i轮比较n-i次两两比较得到最大值，第i轮比较到n-i */

/* 一句话算法：n个数 有n-1轮比较，第1轮比较n-1次,比较到n-1
 *                                第2轮比较n-2次,比较到n-2
 *                                第3轮比较n-3次,比较到n-3
 *                                .........
 *                                第i轮比较n-i次,比较到n-i
 *
 */

#include <cstdio>

int a[10]= {0,3,2,4,9,1,5,7,6,8};
int main(int argc,char **argv)
{
    int n=9;
    int i,j;
    int tmp;
    for(i=1;i<=n-1;i++)
        for(j=1;j<=n-i;j++)
        {
            if(a[j] > a[j+1])
                tmp =a[j],a[j] =a[j+1],a[j+1]=tmp;
                //a[j]+=a[j+1],a[j+1]=a[j]-a[j+1],a[j]-=a[j+1];
        }

    for (i=1;i<=9;i++)
    {
        printf("%d ",a[i]);
    }
    
    return 0;
}
