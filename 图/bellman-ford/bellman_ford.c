#include <stdio.h>
#include <string.h>

#define maxn 1000
int dis[maxn];
int u[maxn],v[maxn],w[maxn];
int n,m,S,T;

int main(int argc, const char *argv[])
{
    int i,j,k,l;
    freopen("ford.in","r",stdin);
    scanf("%d%d%d",&n,&m,&S);
    for(i =1;i<=m;i++)
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
    memset(dis,0x7f,sizeof(dis));
    dis[S] = 0;
    int change;
    for(i =1;i<n;i++)
    {
        change =0;
        for(j=1;j<=m;j++)
        {
            if(dis[u[i]]>dis[v[i]]+w[i])
                dis[u[i]] = dis[v[i]] +w[i],change =1;
            if(dis[v[i]]>dis[u[i]]+w[i])
                dis[v[i]] = dis[u[i]] +w[i],change =1;
        }
        if(change == 0) break;
    printf("%d",dis[T]);
    return 0;
}
