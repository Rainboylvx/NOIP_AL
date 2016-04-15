/*============================================================================
* Title : 全排列
* Author: Rainboy
* Time  : 2016-04-15 16:08
* update: 2016-04-15 16:08
* © Copyright 2016 Rainboy. All Rights Reserved.
*=============================================================================*/


/*  1
 *  1 2  , 2  1
 *
 *
 * 原理:
 *  DFS,每一层挑一个:没有用到的数
 *
 * 设定:
 *  n 为要的求的全排列的娄
 *  depth 深度 范围[0,n-1] 
 * */


#include <cstdio>

int used[1001] = {0}; // 没有使用

int stack[1001];
int n;

void printA(){
    int i;
    for(i=0;i<n;i++)
        printf("%d ",stack[i]);
    printf("\n");
}

void full_A(int depth){
    if(depth == n){
        printA();//输出结果
        return ;
    }

    int i;
    for(i=0;i<n;i++){
        if(!(used[i])){
            used[i] =1;
            stack[depth] = i+1;
            full_A(depth+1);
            used[i] =false;
        }
    }
}



int main(){
	n =2;
	full_A(0);
	return 0;
}
