/*-------------------------------------------------
*  Author:Rainboy
*  time: 2016-04-06 13:47
*  © Copyright 2016 Rainboy. All Rights Reserved.
*-------------------------------------------------*/

/* 对图的DFS,邻接矩阵实现,边集数组更好 */

#include <cstdio>

#define N 101  // 定义一个最大点量
#define M 101  // 最在边量
int n,m;

const int INF = 0x7fffffff / 3;

int G[N][N];
bool vis[N] = {0}; // 0 没有被访问过
void DFS(int x){
    vis[x] = true;
    printf("%c ",x+'A'-1);

    int i;
    for(i=1;i<=n;i++){
        if( !vis[i]  && G[x][i] != INF)
            DFS(i);
    }
}

int main()
{
    freopen("1.in","r",stdin);
    int i,j;
    scanf("%d%d",&n,&m);
    /* 初始化图G */
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            G[i][j] = INF;
        }

    /* 读取数据 */
    char c1,c2;
    for (i=1;i<=m;i++){
        scanf("%c%c",&c1,&c2);
        G[c1-'A'+1][c2-'A'+1] = 1;
        G[c2-'A'+1][c1-'A'+1] = 1;
    }
    DFS(1);
    return 0;
}


