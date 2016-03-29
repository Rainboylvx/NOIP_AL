/*-------------------------------------------------
*  Author:Rainboy
*  time: 2016-03-28 17:33
*  © Copyright 2016 Rainboy. All Rights Reserved.
*-------------------------------------------------*/

/*
 * 单点更新最难的地方主要是一个框架:
 *  - build
 *  - upadte
 *  - query
 *  - pushdown
 *  - pushup
 * */

/*
 * 10
 * 1 2 3 4 5 6 7 8 9 10
 * 4
 * 1 2
 * 3 4
 * 5 6
 * 2 9
 * */

#include <cstdio>

#define maxn 1000

int tree[maxn << 2];

#define lson(rt) (rt <<1)
#define rson(rt) (rt<<1|1)

/*-------------------------------------------------
*  函数: pushup
*       用rt点的孩子来更新rt
*       不同的题目意思用不同的方法
*-------------------------------------------------*/
void pushup(int rt){
    /* 简单的数字和 */
    tree[rt] = tree[lson(rt)] + tree[rson(rt)];
}


/*-------------------------------------------------
*  建树:
*       递归到叶结点
*-------------------------------------------------*/

void build(int l,int r ,int rt){
    if(l == r){
        scanf("%d",&tree[rt]);
        return;
    }
    int m = (l+r) >> 1; //中点
    build(l,m,lson(rt));
    build(m+1,r,rson(rt));
    pushup(rt);
}


/* 最简单的单点更新 */
void upadte(int node,int opr,int l,int r,int rt){
    if(l == r)
    {
        tree[rt] +=opr;
        return;
    }
    int m = (l+r)>>1;
    if(node <=m)
        upadte(node,opr,l,m,lson(rt));
    else
        upadte(node,opr,m+1,r,rson(rt));
    pushup(rt);
}

int query(int l1,int r1,int l,int r,int rt){
    if( l1<=l && r<=r1){
        return tree[rt];
    }
    int ans=0;
    int m =(l+r)>>1;
    if(l1 <=m) ans+=query(l1,r1,l,m,lson(rt));
    if(r1 > m) ans+=query(l1,r1,m+1,r,rson(rt));
    return ans;
}


int main(){
    freopen("2.in","r",stdin);
    int n;
    scanf("%d",&n);
    build(1,n,1);
    int m,i,j,k;
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        scanf("%d%d",&j,&k);
        upadte(j,k,1,n,1);
    }
    printf("%d",query(2,7,1,n,1));
    return 0;
}


