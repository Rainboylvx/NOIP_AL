/*============================================================================
* Title : 归并排序
* Author: Rainboy
* Time  : 2016-04-13 10:31
* update: 2016-04-13 10:31
* © Copyright 2016 Rainboy. All Rights Reserved.
*=============================================================================*/

/* 
 *  算法思想:
 *      分治
 * */

#include <cstdio>

int a[] ={1,7,3,6,5,2};
int tmp[100]; //临时存储的中间数组

void merge_sort(int s,int t){
        //s =start t=T
    int mid,i,j,k;

    if(s==t) return ; //如果区间只有一个数,就返回

    mid = (s+t)>>1; //取中间的点
    merge_sort(s,mid);
    merge_sort(mid+1,t);

    i=s;
    j=mid+1;
    k=s;

    while(i<=mid && j<=t){
        if( a[i] <=a[j]){
            tmp[k]=a[i];k++;i++;
        } else {
            tmp[k]=a[j];j++;k++;
        }
    }

    while(i<=mid) { tmp[k]=a[i];k++;i++;};
    while(j<=t)   { tmp[k]=a[j];k++;j++;};

    for(i=s;i<=t;i++)
        a[i]=tmp[i];
}

int main()
{
    merge_sort(0,sizeof(a)/sizeof(a[0])-1);
    int i;
    for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
        printf("%d ",a[i]);
    return 0;
}
