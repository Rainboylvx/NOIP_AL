#include <cstdio>
#include <vector>
using namespace std;

#define N 100

/* 定义数据结构 */

bool vis[N]; //记录点y是否已经访问过
int link[N]; //记录当前与y节点相连的x节点
int mat[N][N]; //记录连接x和y的边
int xN,yN;      //二分图中 x点,y点的集合


int search(int x){ //寻找增广路
    int i;
    for(i=1;i<=yN;i++){
    
    }
}
