/*-------------------------------------------------
*  Author:Rainboy
*  create: 2016-03-25 12:35
*  © Copyright 2016 Rainboy. All Rights Reserved.
*-------------------------------------------------*/


/*  一句话算法:
 *      如果余数还能分就分,不然输出余数(0不输出)
 * */
#include <cstdio>

int main(){

    int n;
    scanf("%d",&n);

    int cnt=0;
    int s=0;
    //写法一:
    while( n >=(1<<cnt)){
        printf("%d ",(1<<cnt));
        n = n-(1<<cnt);
        cnt++;

    }
    if(n>0)
        printf("%d",n);

    printf("\n");
    //写法二:
    int i;
    scanf("%d",&n);

    for(i=0;i<=1000;i++){
        if(n >= (1<<i))//如果余数比 要分下来的数大
        {
            printf("%d ",(1<<i));
            n=n-(1<<i);
        }
        else{
            printf("%d",n);
            break;
        }
    }

    return 0;
}
