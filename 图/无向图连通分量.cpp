/*-------------------------------------------------
*  Author:Rainboy
*  time: 2016-03-29 21:14
*  © Copyright 2016 Rainboy. All Rights Reserved.
*-------------------------------------------------*/

/* 
 * 注意 此代码没有测试!!! 没有优化
 *   
 *   就是DFS
 * */
#include <cstdio>
#include <cstring>

#define maxn 1000

int G[maxn][maxn];




int vis[maxn]; // 某个是不是 被访问过 0 = 没有
int id[maxn] ; // 记录点所属的连通分量

int cnt=0; // 连通分量的数目,
int n; // 读取的点

void dfs(int v){//点v
    if( vis[v] == 1)
        return;
    vis[v] = 1;
    id[v] = cnt;
    int i
    for(i=1;i<=n;i++)
        if(g[v][i] !=0){
            dfs(i);
        }
}


int main(graph *g){
   int i;
    memeset(vis,0,sizeof(vis));
    memeset(id,0,sizeof(id));
    scanf("%d",&n); // 读取点的数量
    // 读取图
    int i;
    for(i=1;i<=n;i++){
        if(vis[i] == 0){// 没有被访问
            dfs(i);
            cnt++;
        }
    }

    //最的cnt 就是连通分量的数目, 0--->cnt 就是连通分量的编号
    return 0;
}


