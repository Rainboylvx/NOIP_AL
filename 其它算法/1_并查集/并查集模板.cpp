/*-------------------------------------------------
*  Author:Rainboy
*  time: 2016年01月05日 星期二 10时37分31秒
*  © Copyright 2016 Rainboy. All Rights Reserved.
*-------------------------------------------------*/

/* 
 *  并查集理解：
 *  1.并查集是一种树型的数据结构，用于处理一些不相交集合（Disjoint Sets）的合并及查询问题。常常在使用中以森林来表示
 *  2.有两个操作： - 合并两个集合 join() - 判断两个元素是否属于同一个集合 find(x)     所以才叫并查集
 *  3.优化 路径压缩   - 递归法  - 非递归法   注意：通常都是在查找的时候压缩
 *  4.很多时候使用并查集 需要拓展
 * */

/* 一句算法：合并jion,查找压缩 ? */



//初始化
int i;
#define N 1000
int fa[N+1];

for(i=1;i<=N;i++)
    fa[i]=i;


//查找并路径压缩 非递归
int find(int x){
    int t =x;
    while(fa[t] != t) //不停的往上走
        t=fa[t];

    int i = x,j;//路径压缩，再走一便路程，把走过的点都指向根
    while(i != t){
        j= fa[i];
        fa[i] = t; // 把这个点指向根
        i = j;
    }
    
    return t;
}

int path[N]={0};
int find2(int x){
    int count =0;
    while(x != fa[x]){
        path[++count] = x;
        x = fa[x];
    }

    int i;
    for(i=1;i < count;i++){ //这里i < count 是因为 path 记录的第 count 的点一定是指向 root 的,所以可以不用到count
        path[i] = x;
    }
    return x;
}


// 查找 递归法 在面对很深的树的时候 效率很低,且可能会崩溃

int  find3(int x){
    if( x != fa[x]) 
        fa[x] = find(fa[x]);
    else 
        return fa[x];
}


// 合并
int join(int x,int y){ //合并 x, y所在的集合
    int fx = find(x),fy=find(y);
    if( fx != fy)
        fa[fx] = fy;
}


// 合并 优化 ？
