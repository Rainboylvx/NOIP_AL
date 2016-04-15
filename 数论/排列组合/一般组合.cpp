/*============================================================================
* Title : 一般组合
* Author: Rainboy
* Time  : 2016-04-15 16:27
* update: 2016-04-15 16:27
* © Copyright 2016 Rainboy. All Rights Reserved.
*=============================================================================*/


/* 原理:
 *      排在右面的数字大于左面的数字
 * */

void comb(int depth,int p){
    if(depth == n){
        //printA();
        return ;
    }
    int i;
    for(i=p+1;i< n-(m-depth);i++){  //n-(m-depth) 留够够的数
        item[depth]=i;
        comb(depth+1);
    }
}
