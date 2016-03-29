/*-------------------------------------------------
*  Author:Rainboy
*  time: 2016-03-29 15:40
*  © Copyright 2016 Rainboy. All Rights Reserved.
*-------------------------------------------------*/


/* 简单线段树 + 离散化
 * http://cojs.tk/cogs/problem/problem.php?pid=1682
 *
 * */

#include <cstdio>
#include <cstring>
#include <algorithm> // 为了用sort
using namespace std;

#define lson(rt) (rt<<1)
#define rson(rt) (rt<<1|1)

#define maxn 1111 //因为 M <=1000

bool hasht[maxn] = {0}; // 用来判断 某一个数有没有找到过 0 代码没有找到

int x[maxn<<4]; // !!! 第一次开了 maxn*3 还是太小了
int tree[maxn<<4]; // 存树

int li[maxn],ri[maxn];//用来存海报

int cnt = 0;

/* pushdown  -- lazy*/
void pd(int rt){
    if(tree[rt] != -1){ // 这个点有值
        tree[lson(rt)] = tree[rson(rt)] = tree[rt];
        tree[rt]=-1;
    }
}

void update(int l1,int r1,int c,int l,int r,int rt){
    if(l1 <=l && r<=r1){
        tree[rt] = c;
        return ;
    }
    pd(rt);
    int m = (l+r)>>1;
    if(l1<=m) update(l1,r1,c,l,m,lson(rt));
    if(r1>m) update(l1,r1,c,m+1,r,rson(rt));
}


void query(int l,int r,int rt)//找到l == r 的点的值有多少不铜
{
    if(l == r){
		if(hasht[tree[rt]] == false && tree[rt] !=-1)
		{
			hasht[tree[rt]]= true;
			cnt++;
		}
		return ;
    }
    pd(rt);
    int m =(l+r)>>1;
    query(l,m,lson(rt));
    query(m+1,r,rson(rt));
}
int B(int m) // B型离散化,m代表有数组存的值的数量
{
    //去重
    int i;
    int k=1;
    for(i=1;i< m;i++)
        if(x[i]!=x[i-1])
            x[k++] = x[i];
    //中间加值
    for(i=k-1;i>0;i-- )
        if(x[i] != x[i-1]+1)
            x[k++] = x[i-1]+1;
    sort(x,x+k);
    return k;//最有有k个值
}

int bin(int x,int k,int a[]){
    int l=0;int r=k-1;
    while(l<=r){
        int mid= (l+r)>>1;
        if(a[mid] == x) return mid;
        if(a[mid] < x) l=mid+1;
        else r=mid-1;
    }
    return -1;
}
int main(){
    freopen("ha14d.in","r",stdin);
    freopen("ha14d.out","w",stdout);
    int t,n;
    scanf("%d%d",&t,&n);
    int i,j;
    int m=0;
    for(i=0;i<n;i++){ //读n行,这里不考虑超出墻的情况
        scanf("%d%d",&li[i],&ri[i]);
        x[m++] = li[i];
        x[m++] = ri[i];
    }
    sort(x,x+m);
    m = B(m);
    memset(tree,-1,sizeof(tree));

    for(i=0;i<n;i++){
        int l = bin(li[i],m,x);
        int r = bin( ri[i],m,x);
        update(l,r,i,0,m,1);//因为墻可以从0开始;
    }

    query(0,m,1);
    printf("%d",cnt);
    return 0;
}
