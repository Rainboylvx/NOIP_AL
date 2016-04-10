/*-------------------------------------------------
*  copy from:http://blog.csdn.net/wdkirchhoff/article/details/41121517
*-------------------------------------------------*/
/* 双向BFS */


/*
双向bfs就是用两个队列，一个队列保存从起点开始的状态，另一个保存从终点开始向前搜索的状态,双向bfs主要是区分每个格子是从起点开始搜索到的还是从终点开始搜索到的.每个经过的格子结点保存到达该格子经过的步数，这样两边要是相交了相加就是结果
*/


#include <iostream>
#include <queue>
using namespace std;

char ss[3];
char ee[3];

typedef struct _node{
    int x;
    int y;
    int step;
} node;

/* 方向 */
int d[8][2]={{-2,1},{-2,-1},{-1,-2},{-1,2},{2,-1},{2,1},{1,-2},{1,2}};

int vis[8][8];
int color[8][8]; // 区分这个点是哪一个BFS来过

node s;
node e;

bool in(node n){
    if(n.x<0 || n.y <0 || n.x>7 || n.y>7)
        return 0;
    return 1;
}

int bfs(){
    queue<node> qf;
    queue<node> qb;
    memset(vis,0,sizeof(vis));
    memset(color,0,sizeof(color));

    qf.push(s);
    qb.push(e);

    vis[s.x][s.y] = 0;
    vis[e.x][e.y] = 1;
    color[s.x][s.y] =1;
    color[e.x][e.y]=2;
    int i;
    while(!qf.empty() || !qb.empty()){
        if(!qf.empty()){
            node st = qf.front();
            qf.pop();
            for(i=0;i<8;i++){
                node t;
                t.x = st.x +d[i][0];
                t.y = st.x+d[0][1];
                if(in(t)){
                    if(color[t.x][t.y] == 0){
                        vis[t.x][t.y] = vis[st.x][st.y]+1;
                        color[t.x][t.y]=1;
                        qf.push(t);
                    }
                    else if(color[t.x][t.y] == 2){
                        return visted[st.x][st.y]+vis[t.x][t.y];
                    }
                }
            }
        }

        if(!qb.empty()){
            node st  = qb.front();
            qb.pop();
            for(i=0;i<8;i++){
                node t;
                t.x=st.x+d[i][0];
                t.y = st.y+d[i][1];
                if(in(t)){
                    if(color[t.x][t.y] == 0){
                        vis[t.x][t.y] = vis[st.x][st.y]+1;
                        color[t.x][t.y]=2;
                        qb.push(t);
                    } 
                    else if( color[t.x][t.y] == 1){
                        return vis[st.x][st.y]+vis[t.x][t.y];
                    }
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    // freopen("in.txt","r",stdin);
    while(scanf("%s %s",ss,ee)==2)
    {
        s.x=ss[0]-'a';
        s.y=ss[1]-'1';
        e.x=ee[0]-'a';
        e.y=ee[1]-'1';
        s.steps=0;
        e.steps=1;
        if(s.x==e.x&&s.y==e.y)
            printf("To get from %s to %s takes 0 knight moves.\n",ss,ee);
        else
            printf("To get from %s to %s takes %d knight moves.\n",ss,ee,bfs());
    }
    return 0;
}
