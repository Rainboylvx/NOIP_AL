/*==================================
*Title :SPFA算法版本1，有队列
*Author:Rainboy
*Time  :2015-12-28 17:55
*update:date
*© Copyright 2015 Rainboy. All Rights Reserved.
*=================================*/
/*-----------------------------------------------------------------------------
 *  SPFA算法原理：
 *      加入了队列优化的Bellman_ford算法；有些情况下，ford算法会重复运算某些点；
 *      SPFA 当一个点的dis被更新的时候，也许与他相邻的点也需要被更新，所以把这个点加入队列
 *      如果队列为空，那么就结束运算
 *   注意：加入点的进入队列的时候，还需要判断，点是否已经在队列里了，如果已经在，就不需要加入队列了  
 *          一个点被拿出队列的时候，也许还可以在被放进去，所以出队时要设为false 
 *-----------------------------------------------------------------------------*/
#include <cstdio> 
#include <cstring>

#define INF 0x7fffffff
#define maxv 1000
#define maxe 1000
#define lq 2*maxv+5 //队列长度  能找都要那么多

int dis[maxv];
int queue[lq+1];
int head=1,tail=0;
bool exist[maxv] = {0};
int pre[maxv]={0};

//边集数组所用到的数据
int u[maxe],v[maxe],w[maxe];
int first[maxv];
int next[maxe];


int main(){
    //初始化
    int s;//起点
    int n,e;// 多少点，多少边
    int i,j,k,l;
    scanf("%d%d%d",&n,&e,&s);
    
    for(i=1;i<=n;i++)
        dis[i] =INF;
    
    dis[s] =0;
    queue[1] =s;
    head=1,tail=2;
    exist[s] = true;

    for(i=1;i<=e;i++)
        next[i] = -1;
    for(i=1;i<=2*e;i+=2){
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
        v[i+1] = u[i],u[i+1] =v[i],w[i+1]=w[i]; //无向图 一条边存两遍

        next[i] = first[u[i]];
        first[u[i]] = i;

        next[i+1] = first[u[i+1]];
        first[u[i+1]] =i+1;

    }
    
    int tmp;
    while( head < tail){
        tmp = queue[head];
        head = (head % lq) +1;
        exist[tmp] = false;

        for(i=first[tmp];i!=-1;i=next[i])
            if(dis[v[i]] > dis[tmp] + w[i]){
                dis[v[i]] = dis[tmp] +w[i];
                pre[v[i]] = tmp;

                if(!exist[v[i]]){
                    queue[tail]=v[i];
                    tail = (tail % lq) +1;
                    exist[v[i]] = true;
                }
            }
    }
}
