/*==================================
*Title :dijkstra算法
*Author:Rainboy
*Time  :2015-12-28 16:03
*update:2015-12-28 16:03
*© Copyright 2015 Rainboy. All Rights Reserved.
*=================================*/

#include <cstdio> 

#define INF 0x7fffffff
#define max_e 999
#define max_v 999

int dis[max_v];
bool sn[max_v]={0}; //定义sn（snode)判断是不是 加入的点

int G[max_v][max_v];//二维数组来存图

int main(){
    int v,e;
    int i,j,k,l;
    int min;
    //初始化
    dis[0] =0;
    int tmp;
    for(i=2;i<=v;i++)//一共有v个点，已经加入0号点，剩下v-2+1个点
    {
        min = INF ;
        tmp = -1;
        for(j=1;j<=v-1;i++)//
        {
            //找到未加入的最小值
            if(sn[j]==true && dis[j] <min){
                tmp=j;
                min =dis[j];
            }

            if( tmp != -1)//表示找到了
                sn[tmp] =true;
            else
                break;

            //用找到的最小值去更新其它的点
            for(j=0;j<v;j++)
                if(!sn[j] && G[tmp][j] !=INF)//不是sn里的点且有连接
                {
                    //relax 操作
                    if(dis[j] > dis[tmp] + G[tmp][j])
                        dis[j] = dis[tmp] + G[tmp][j];
                }
        }
    }
    return 0;
}
