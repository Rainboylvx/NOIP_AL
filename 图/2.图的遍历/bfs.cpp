/*-------------------------------------------------
*  Author:Rainboy
*  time: 2016-04-11 11:30
*  © Copyright 2016 Rainboy. All Rights Reserved.
*-------------------------------------------------*/

/*  BFS过程:
 *      把相邻点,加入list中,并且代码从list中取值,访问,直到list为空
 *
 * */

#include <deque>
#include <cstdio>
using namespace std;

#define N 100;
queue<int> q; //队列
bool vis[N]=0;

void BFS(int s){
    q.push(s);vis[s] =1;
    do{
        int a = q.front(); q.pop();
        printf("%d ",a);
        int i;
        for(i=1;i<=n;i++){
            if(!vis[i] && G[a][i] !=INF){
                q.push(i);
                vis[a]=1;
            }
        }while(!q.empty());
    }
}


int main(){
    /* 读取,采用最简单的邻接矩阵 */
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
    return 0;
}
