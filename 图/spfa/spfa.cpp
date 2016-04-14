/*============================================================================
* Title : SPFA算法--边集数组实现
* Author: Rainboy
* Time  : 2016-04-12 10:13
* update: 2016-04-12 10:13
* © Copyright 2016 Rainboy. All Rights Reserved.
*=============================================================================*/




/*-----------------------------------------------------------------------------
 *  SPFA算法原理：
 *      加入了队列优化的Bellman_ford算法；有些情况下，ford算法会重复运算某些点；
 *      SPFA 当一个点的dis被更新的时候，也许与他相邻的点也需要被更新，所以把这个点加入队列
 *      如果队列为空，那么就结束运算
 *   注意：加入点的进入队列的时候，还需要判断，点是否已经在队列里了，如果已经在，就不需要加入队列了
 *          一个点被拿出队列的时候，也许还可以在被放进去，所以出队时要设为false
 *-----------------------------------------------------------------------------*/

/* 自己维护队列的版本 */
#include <cstdio>
#include <cstring>

#define maxv 1000
#define maxe 1000

const int INF = 0x7fffffff/3;

const int lq =  2*maxv+5; //队列长度  能找都要那么多

int dis[maxv];
int queue[lq+1];
int head=1,tail=0;
bool exist[maxv] = {0};//点是否在队列中
int pre[maxv]={0};      //前趋

//边集数组所用到的数据
int u[maxe],v[maxe],w[maxe];
int first[maxv];
int next[maxe];


int main(){
    freopen("1.in","r",stdin);
    //初始化
    int s,t;//起点,终点
    int n,e;// 多少点，多少边
    int i,j,k;

    scanf("%d%d",&n,&e);
    scanf("%d%d",&s,&t);

    for(i=1;i<=n;i++)
        dis[i] =INF;

    /* s点加入队列 */
    dis[s] =0;
    queue[1] =s;
    head=1,tail=2;
    exist[s] = true;

    /* 边集数组来存图 */
    for(i=1;i<=n;i++)   first[i]=-1; //初始化first
    for(i=1;i<=2*e;i+=2){
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
        v[i+1] = u[i],u[i+1] =v[i],w[i+1]=w[i]; //无向图 一条边存两遍

        next[i] = first[u[i]];
        first[u[i]] = i;

        next[i+1] = first[u[i+1]];
        first[u[i+1]] =i+1;
    }

    int tmp;
    while( head < tail){ //队列非空
        tmp = queue[head];  //取首点
        head = (head % lq) +1;//循环队列
        exist[tmp] = false;     //不在队列中

        for(i=first[tmp];i!=-1;i=next[i])   //更新周围的点
            if(dis[v[i]] > dis[tmp] + w[i]){
                dis[v[i]] = dis[tmp] +w[i];
                pre[v[i]] = tmp;

                /* 被更新的点不在队列中,那就加入队列中 */
                if(!exist[v[i]]){
                    queue[tail]=v[i];
                    tail = (tail % lq) +1;
                    exist[v[i]] = true;
                }
            }
    }

    /* 输出终点dis */
    printf("dis[%d] = %d\n",t,dis[t]);

    /* 输出路径 */
    for(i=t;i!=0;i=pre[i])
        printf("%d ",i);
    return 0;
}
