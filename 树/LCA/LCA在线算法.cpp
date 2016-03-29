/*-------------------------------------------------
*  Author:Rainboy
*  time : 2016-03-29 18:38
*  © Copyright 2016 Rainboy. All Rights Reserved.
*-------------------------------------------------*/

/* 
 *  1.预处理
 *  2.a,b 不在同一层 则a,b 移到同一层
 *  3. 开始爬树,停下来后,father[a] 就是所求值
 * */

/*
数据:
1
1 2 3 4
3 5 6 7
6 8 9
7 10 11
10 12 13
*/

#include <cstdio>
#include <cstring>
#include <cmath> //为了使用log()函数

int n; // 总共有n个点

int d[100] = {0};//每个点的深度
int f[100];//每个点的父亲
int p[100][100];

void st(){
    int i,j;
    memset(p,-1,sizeof(p));
    for(i=1;i<=n;i++) // n个点,dp边界
        p[i][0]=f[i];

    //n个点,理论最深是n,也就是最大有n-1倍祖先,我们算大一点:算成n倍祖先
    // 2^j =n --->j=log(n)/log(2)
    for(j=1;j<=(int)(log(n)/log(2));j++)
        for(i=1;i<=n;i++)
            if(p[i][j-1] != -1)// [1] p[i][j-1] != -1 表明可以用自己去更新别人,为什么要有这个判断?
                p[i][j] = p[p[i][j-1]][j-1];
}

// 求点a,b的最近公共祖先
int LCA(int a,int b){
    /*    先判断是否 d[a] > d[b] ，如果是的话就交换一下(保证 a 的深度小于b，方便下面的操作) */
    int i;
    if(d[a] > d[b])
    {
        int tmp =a;
        a=b;
        b=tmp;
    }

    /* 转为找同层结点  d[a] <= d[b] */
    /* 这种找法 能成功的原因,看折半查找原理*/

    int k = (int)(log(d[b]-1)/log(2));//公式 root 点是b点d[b]-1倍祖先
    for(i=k;i>=0;i--){
        if(d[b]-(1<<i) >=d[a])
            b=p[b][i];
    }
    if(a == b)    //这种情况:b是a的子树
        return a;

    //爬树中,原理:拆半查找原理
    k = (int)(log(d[b]-1)/log(2));

    for(i=k;i>=0;i--)
        if(p[a][i] != p[b][i])
        {
            a=p[a][i];
            b=p[b][i];
        }

    return p[a][0];
}


int main(){
    //太难受了,手动建立树
    n=13;

    int root =1;
    d[root] =1;
    f[root] = -1;// [2]  在这里,f[root] =-1 比较好,可以少算很多
    f[3]=f[2]=f[4] =root;    d[3] = d[2]=d[4]=d[root]+1;
    f[5]=f[6]=f[7] =3;        d[5] = d[6] =d[7] =d[3]+1;
    f[10]=f[11] =7;            d[10]=d[11] =d[7]+1;
    f[12]=f[13]=10;            d[12]=d[13]=d[10]+1;
    f[8]=f[9]=6;                d[8]=d[9]=d[6]+1;


    //预处理
    st();
    //LCA
    int tmp = LCA(9,12);
    printf("%d",tmp);
    return 0;
}
