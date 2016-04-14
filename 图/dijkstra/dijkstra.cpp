/*-------------------------------------------------
*  Author:Rainboy
*  time: 2016-04-11 16:29
*  © Copyright 2016 Rainboy. All Rights Reserved.
*-------------------------------------------------*/

/*
 *  Dijstra算法: -- >贪心
 *      有两个点的集合: A 确定的最短路径的点, B没有确定最短路径的点
 *      每一次从B中找到dis[b]最小的点c,把c加入B
 *      不停这样下去,直到所有点都成为A
 * */

#include <cstdio>
const int INF=0x7fffffff/3;
#define max_e 999
#define max_v 999

int dis[max_v];
bool vis[max_v]={0}; //定义sn（snode)判断是不是 加入的点

int G[max_v][max_v];//二维数组来存图
int pre[max_v] ={0};

int n,m;//点和边的数量
int s,t;//起点 终点

void diskstra(){
    int i,j,k;

    /* 计算n次,因为每一次加入一个数进vis */
    for(i=1;i<=n;i++){
        int k,min = INF;

        /* 找到加入点中最小的 */
        for(j=1;j<=n;j++)
            if(!vis[j] && dis[j] < min)
                min = dis[j] ,k=j;
        vis[k]=true;
        /* 用找到的k去更新其它点 */
        for(j=1;j<=n;j++)
            if(G[k][j] != INF && dis[j] >G[k][j]+dis[k]) {//相邻边,且可以更新
                dis[j] = dis[k]+G[k][j];
                pre[j] =k;
            }
    }
}

int main(){
    freopen("1.in","r",stdin);
    int i,j,k;
    scanf("%d%d",&n,&m);
    scanf("%d%d",&s,&t);

    //读取图
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            G[i][j]=INF;
    for(i=1;i<=m;i++){
        scanf("%d%d",&j,&k);
        scanf("%d",&G[j][k]);
        G[k][j]=G[j][k];
    }
    for(i=1;i<=n;i++)   dis[i] = INF;
    dis[s] = 0; //起点dis 为0
    diskstra();

    //输出
    for(i=t;i!=0;i=pre[i])
        printf("%d ",i);
    return 0;
}
