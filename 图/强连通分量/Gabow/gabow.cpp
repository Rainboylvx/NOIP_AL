
/*-------------------------------------------------
*  Author:Rainboy
*  time: 2016-03-30 23:21
*  © Copyright 2016 Rainboy. All Rights Reserved.
*-------------------------------------------------*/

/*  Gabow  算法和tarjan 一样,都是通过DFS时,不能返回到最早的点的判断的
 *
 *
 * */


#include <cstdio>
#include <cstring>


#define maxn 1000


int dfn[maxn]={0},low[maxn]={0};
int color[maxn];

int s[maxn],p[maxn],st=0,pt=0;

/* 图的边集数组 */
int u[maxn],v[maxn];
int first[maxn];
int next[maxn];

int cnt=0,id=0;

void printps(){
    int i;
    for(i=1;i<=st;i++)
        printf("%-2d ",s[i]);
    printf("\t");
    for(i=1;i<=pt;i++)
        printf("%-2d ",p[i]);
    printf("\n");

}
void gabow(int i){
    int j;
    dfn[i] = ++id;
    s[++st] = i;
    p[++pt] = i;
    printps();
    int e = first[i];
    for(;e!=-1;e=next[e]){
        j=v[e];
        if(dfn[j]== -1)//没有被访问过
            gabow(j);
        else if (color[j] == -1){ // 访问过的点:1, 是这个分量, 另一个分量的
            while(dfn[p[pt]] > dfn[j]) //大于的点 弹出
                pt--;
            printps();
        }
    }
    if(p[pt] == i){
        printf("know anwster:");
        pt--;
        cnt++;
        do {
            j=s[st--];
            color[j] = cnt;
            printf("%d ",j);
        }
        while(j !=i);
        printf("\n");
    }
}

int main(int argc,char **argv)
{
    freopen("1.in","r",stdin);
    memset(first,-1,sizeof(first));
    memset(color,-1,sizeof(color));
    memset(dfn,-1,sizeof(dfn));
    int n,t;
    scanf("%d%d",&n,&t);
    int i;
    for(i=1;i<=n;i++){
        scanf("%d%d",&u[i],&v[i]);
        next[i] = first[u[i]];
        first[u[i]] =i;
    }

    for(i=1;i<=t;i++){
        if(dfn[i] == -1)
            gabow(i);
    }
    printf("%d\n",cnt);
    return 0;
}
