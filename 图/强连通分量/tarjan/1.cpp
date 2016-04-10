/*-------------------------------------------------
*  Author:Rainboy
*  time: 2016-03-30 15:42
*  © Copyright 2016 Rainboy. All Rights Reserved.
*-------------------------------------------------*/


/* -----------
 *  原理,:一个分量里的点都可以互相访问
 * 算法实现:
 *      1.初始化 dfn[i], low[i]
 *      2.对i所有相临的结点j
 *          1.if !vis[j] dfs[j]
 *          2.if vis[j] low[i] =dfn[j]
 *      3.if dfn[i] = low[i]
 * */


#include <cstdio>
#include <cstring>


#define maxn 1000 //最多的点
bool instack[maxn] ={0}; // =false

int low[maxn];
int dfn[maxn] ={0};

int color[maxn]; // color[i] 点i的强连通分量

int stack[maxn],top; // 自己维护的stack ,可以用 STL stack
int cnt =0,index=0;

//存图
int first[maxn];
int u[maxn],v[maxn],next[maxn];

void tarjan(int x){
    int j;
    dfn[x] = low[x] = ++index;
    instack[x] =true;
    stack[++top] = x;
    int e = first[x];
    for(; e != -1; e = next[e]){
        j = v[e];
        if( !dfn[j] ) // dnf[j] !=0 表示 这个点没有被访问过
        {
            tarjan(j);
            if(low[j] < low[x])
                low[x] = low[j];
        } 
        else if(instack[j] && low[j] < low[x])
            low[x] = low[j];
    }
	if(dfn[x] == low[x])
        {
            cnt++;
            do{
                j=stack[top--];
                instack[j] = false;
                color[j] = cnt;
            }
            while(j !=x);
        }
}

int main(){
    freopen("1.in","r",stdin);
    top = 0;
    int n,i,k;
	int T;
    memset(first,-1,sizeof(first));
    scanf("%d%d",&n,&T);
    //读取图 这里用边集数组
    for(i=1;i<=n;i++){
        scanf("%d%d",&u[i],&v[i]);
        next[i] = first[u[i]];
        first[u[i]] = i;
    }
    for(i=1;i<=T;i++){ // 遍历所有点
        if(!dfn[i]) // 没有被访问过
            tarjan(i);
    }
    printf("%d\n",cnt);
    return 0;
}
