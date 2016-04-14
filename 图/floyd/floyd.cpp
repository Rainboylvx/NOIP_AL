/*============================================================================
* Title : floyd 算法的实现
* Author: Rainboy
* Time  : 2016-04-12 11:13
* update: 2016-04-12 11:13
* © Copyright 2016 Rainboy. All Rights Reserved.
*=============================================================================*/

/*  floyd 算法的本质:DP
 *      f(i,j) = min{f(i,k)+f{k,j}}
 *
 *  floyd算法的原理:
 *
 * */
#include <cstdio>
#include <cstring>

#define N 100

const int INF = 0x7fffffff/3;

int f[N][N],pre[N][N];

int n,m;//n个点,m条边
int s,t;//起点 终点

void floyd(){
    int k,i,j;
    for(k=1;k<=n;k++){ //k在最外层

        for (i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(f[i][k]+f[k][j]<f[i][j]){
                    f[i][j] = f[i][k]+f[k][j];
                    pre[i][j]=k;
                }
    }
}

int main(){
    freopen("1.in","r",stdin);
    int i,j,k,l;
    scanf("%d%d",&n,&m);
    scanf("%d%d",&s,&t);

    /* 初始化 */
    memset(pre,-1,sizeof(pre));
    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++)
            f[i][j] =INF;

    for(k=1;k<=m;k++){
        scanf("%d%d%d",&i,&j,&l);
        f[i][j]=f[j][i]=l;
    }

    /* 调用floyd */
    floyd();

    /* 输出dis */
    printf("%d\n",f[s][t]);

    /* 输出路径 */
    //printf("%d ",t); //终点

    for(j=t;j!=-1;j=pre[s][j])
        printf("%d ",j);
    printf("%d ",s); //起点,为什么这里要输出呢,因为f[x][x] = INF f[1][1] 不能更新f[1][2]

    return 0;
}
