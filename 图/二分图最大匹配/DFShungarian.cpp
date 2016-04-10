// 一个DFS 找增广路 不停取反的过程，只不过DFS 过程比较新奇，想法比较简练，果然是算法的艺术

//讲解过程 ：概念   - 增广路 ---手动增广路 ---DFS 匈牙利树概念 ---转换算法1，转换算法2
// 二分图匹配的 转换
/*Matrix67
研究了几个小时，终于明白了。说穿了，就是你从二分图中找出一条路径来，让路径的起点和终点都是还没有匹配过的点，并且路径经过的连线是一条没被匹配、一条已经匹配过，再下一条又没匹配这样交替地出现。找到这样的路径后，显然路径里没被匹配的连线比已经匹配了的连线多一条，于是修改匹配图，把路径里所有匹配过的连线去掉匹配关系，把没有匹配的连线变成匹配的，这样匹配数就比原来多1个。不断执行上述操作，直到找不到这样的路径为止。

*/

#include <cstdio>
#include <cstring>


#define N 100  //最多点数
/* 定义我们的数据结构 */
int G[N][N];    //用来存图,邻接矩阵
int xN,yN;
int match[N];   //某个点所匹配的点
int vis[N];  //点是不已经访问过,也就是这个点是不是在我们找的增广路中

int cnt =0; //记数
bool dfs(int u){
    int i;
    //所有和u相连的点的
    for(i=1;i<=xN;i++){
        if(G[u][i] !=-1  && vis[i]==0){//sh相连 且没有被加入路中
            vis[i] = 1;     //放入我们找的增广路中
            /*点i有两种可能性:1,不是一个匹配点,也就是没有被加入路中
                              2,是一个匹配点,那就去点i的匹配的的点开始dfs,直到找到一个非匹配点,也就是增广路的结尾
                              返回时,取反
            */
            if(match[i] ==-1 || dfs(match[i])){ //这里建议调试跟一下数据
                match[u] = i;
                match[i] = u;
                return 1;
            }
        }
    }
    return 0;
}

int hungarian(){
    memset(match,-1,sizeof(match));
    int i;
    for(i=1;i<=yN;i++){
        memset(vis,0,sizeof(vis));
        if(match[i] == -1) //从一个没有匹配的点,开始找,那什么是循环yN次呢
            if(dfs(i))
                cnt++;
    }
    return cnt;

}
int main()
{
    /* 读取数据 */
    int i,j,k,l;
    scanf("%d%d",&xN,&yN);//  二分图的 两侧分别有多少点
    scanf("%d",l);  //下面有多少边
    memset(G,-1,sizeof(G));
    for(i=1;i<=l;i++){
        scanf("%d%d",&j,&k);
        G[j][k] = G[k][j] =1;
    }
    
    k = hungarian();
    printf("%d",k);
    return 0;
}


