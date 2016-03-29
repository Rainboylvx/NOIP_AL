/*-------------------------------------------------
*  Author:Rainboy
*  time: 2016-03-29 19:30
*  © Copyright 2016 Rainboy. All Rights Reserved.
*-------------------------------------------------*/


/*  理解tarjan 就是理解DFS后序输出的过程
 *      tarjanDFS
 *          1. 进入某个点a,  fa[a] =a 自己形成一个集合
 *          2.if hasChild[a] == true tarjanDFS(child[a]) 如果a有孩子,就DFS a的child
 *              2.1 fa[b] =a    a的孩子b 的fa 改为a
 *          3.a的所有子树输出完,正要输出a ,
 *              3.1 find[a,x] or [x,a]
 *              3,2 if visted[x]== false -->lca[a,x] = fa[x]
 *
 * */

/*ver 1.0
代码还不是很完善和精简
*/

#include <cstdio>

struct _q{
    int a;
    int b;
}q[3]={{4,6},{5,7},{5,6}};


struct node{
    struct node *child[2];
    int val;
    bool vis;
};
node mynode[100];

int f[100]= {0};//并查集用

int find(int x){
    int r =x;
    int tmp;
    while(f[r] != r)//身上找
        r=f[r];
    while(f[x] !=x)
    {
        tmp =f[x];
        f[x] = r;
        x=tmp;
    }
    return r;
}

//把点y所在的集合 加入 点x 所在的集体
void un(int x,int y){ 
    if(find(x) != find(y))
    {
        int root = find(y);
        f[root] = x;
    }
}

void tarjanDFS(node *x){
    int i;
    f[x->val] =x->val;//自己形成一个集合，路过
    for(i=0;i<2;i++){
        if(x->child[i] !=NULL)
            tarjanDFS(x->child[i]);
        //点x的所有子树输出了
        if(x->child[i] !=NULL)
            un(x->val,x->child[i]->val);
    }
    //所有的子树都已经输出了
    x->vis = true;
    for(i=0;i<3;i++){//处理查询
        if(q[i].a == x->val && mynode[q[i].b].vis == true){
            printf("LCA(%d,%d)=%d\n",q[i].a,q[i].b,find(q[i].b));
        }
        if(q[i].b == x->val && mynode[q[i].a].vis == true){
            printf("LCA(%d,%d)=%d\n",q[i].a,q[i].b,find(q[i].a));
        }
    }

}


// struct node mynode[100] 这种方法也对,这种是c语言风格
int n,root;
int main(){
    freopen("1.in","r",stdin);
    int i,j,k,l;
    for(i=0;i<100;i++){ //初始化 并查集
        f[i] = i;
        mynode[i].val = i;
        mynode[i].vis = false;
        mynode[i].child[0] = mynode[i].child[1]=NULL;
    }
    scanf("%d%d",&n,&root);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&j,&k,&l);
        
        if( k == -1)
            mynode[j].child[0] = NULL;
        else
            mynode[j].child[0] = &mynode[k];
            
        if(l == -1)
            mynode[j].child[1] = NULL;
        else
            mynode[j].child[1] = &mynode[l];
    }
    tarjanDFS(&mynode[root]);
    return 0;
}
