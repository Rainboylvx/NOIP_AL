/*==================================
*Title :Bellman Ford算法
*Author:Rainboy
*Time  :2015-12-28 15:02
*update:2015-12-28 15:02
*© Copyright 2015 Rainboy. All Rights Reserved.
*=================================*/


/* Bellman-Ford算法的思想:
 *      第一次枚举所有的边,用A点更新B点,最多n-1轮更新即成功
 *      本质:DP
 *
 * */
#include <cstdio>
#define maxn 9999
#define maxe 9999
typedef struct edge_t{
    int u;      //边的前一个点
    int v;      //边的后一个点
    int lang;   //边的长度
}edge;

edge E[maxe];
int dis[maxn];

int main()
{
    int num_node,num_e;
    int i,j,k,l;
    scanf("%d%d",&num_node,&num_e);
    for(i=1;i<=num_e;i++){   //读取边上的两个点，和边长
        scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].lang);
    }
    
    dis[0]=0;
    for(i=1;i<=num_node-1;i++){
        dis[i]= 0x7fffffff /3;
    }
    
    //进行bellman-ford
    for(i=1;i<=num_node-1;i++)
        for(j=1;j<=num_e;j++){
            int &x = E[j].u,&y=E[j].v,&len = u[j].lang;
            if(dis[x] > dis[y] + len)
                dis[x] = dis[y] + len;

            if(dis[y] > dis[x] + len)
                dis[y] = dis[x] + len;
        }
    //代码完成
    for(i=1;i<=num_e;i++){
        printf("dis[%d]=%d\n",i,dis[i]);
    }
    return 0;
}





