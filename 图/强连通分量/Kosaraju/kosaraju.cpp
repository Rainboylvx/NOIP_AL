#include <cstdio>
#include <cstring>

#define N 101 //最多点
#define M 101 // 最多边

int n;      //点的数量
int m;      //边的数量
/* 边集数组 */
int u[M],v[M];
int first[N];
int next[M];


/* 边集数组2*/
int u2[M],v2[M];
int first2[N];
int next2[M];

int vis[N] = {0};// 点是不是已经访问
int cnt=0;

/* 栈 */
int  stack[N];//栈
int top =0; //栈顶

void dfs1(int k){
    vis[k] = 1; // 点k已经访问过
    int i;
    for(i=first[k];i!=-1;i=next[i]){
        if(vis[v[i]] != 1)
            dfs1(v[i]);
    }
    stack[++top] = k; //记录出栈顺序,注意这里top的变化
}

void dfs2(int k){
    vis[k] = cnt; // 点k是哪是强连通分量,也就是DFS染色
    int i;
    for(i=first2[k];i!=-1;i=next2[i]){
        if(vis[v2[i]] == 0)   //没有被访问过
            dfs2(v2[i]);
    }
}

int kosaraju(){
    top = cnt =0;
    memset(vis,0,sizeof(vis));

    int i;
    for(i=1;i<=n;i++){
        if(vis[i]== 0)
            dfs1(i);
    }

    memset(vis,0,sizeof(vis));

    for(i=top;i>=1;i--){
        if(vis[ stack[i] ] == 0){
            cnt++;
            dfs2( stack[i] );
        }
    }

    return cnt;
}

int main(int argc,char **argv)
{

    freopen("1.in","r",stdin);
    int i;
    /* 读取数据 */

    memset(first,-1,sizeof(first));
    memset(first2,-1,sizeof(first));
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++){
        scanf("%d%d",&u[i],&v[i]);
        next[i] = first[u[i]];
        first[u[i]] = i;

        u2[i]=v[i];
        v2[i]=u[i];
        next2[i]  = first2[u2[i]];
        first2[u2[i]] = i;
    }

    kosaraju();
    printf("%d\n",cnt);
    return 0;
}
