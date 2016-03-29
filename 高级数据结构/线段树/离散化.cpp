/*-------------------------------------------------
*  Author:Rainboy
*  time: 2016-03-28 18:42
*  © Copyright 2016 Rainboy. All Rights Reserved.
*-------------------------------------------------*/

/* 
 * 这里只写有关离散化的代码
 *      离散化:1.普通离散化  2.区间离散化
 *
 *      五个点
 *      1 2 3 3 100000 -->求这个五个点之间的信息-->离散化:1 2 3 4
 *
 *      1.能把数字 离散化  2. 能找某个数离散化之后对应的化 -->二分查找
 *
 * */


/* 
 * 10
 * 1 2 2 3 3 5 5 5 1000 1000
 * */


#include <algorithm>
#include <cstdio>
using namespace std;
int a[10001] = {0};
int n; // 读取数的长度



/*  离散化原理 后一个数和前一个数 不等就加入
'    int b[maxn];
    int m=1;
    b[0]=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i] !=a[i-1])
            b[m++] =a[i];
    }

*/


/*  普通离散化,只是找到m 去重排序后所对应的值 */
int  A(){
    //首先排序
    sort(a,a+n);
    
    //去重
    int i,m=1;
    for(i=1;i<=n;i++)
        if(a[i] != a[i-1])
            a[m++] =a[i];
    //最后 1-->m  这个就是区域
    return m;
}

/* 处理区域类 1 2 5 6   1 2 4 6   对应的都是 1 2 3 4 但是不对*/
int B(){
    //首先排序
    sort(a,a+n);
    
    //去重
    int i,m=1;
    for(i=1;i<=n;i++)
        if(a[i] != a[i-1])
            a[m++] =a[i];
    //相临的数 a b  b-a >1---->a,a+1 b
    for(i=m-1;i>0;i--)
        if(a[i]!=a[i]+1)
            a[m++]=a[i-1]+1;
    sort(a,a+m);
    return m;

}

/* 找到 x 离散化后的值 y,使用二会查找*/
/* 二分查找能过 l,r 来确定 mid的值*/

/*  废弃  要写的代码太多 
int bin(int x){ // x 这个数值 所在的位置
    int l=0,r=n-1;
    while(l <= r){
        int mid = (l+r)>>1;
        if(a[mid] < x) {//那就是真正的值在 右边
            l=mid+1;
        }
        else if(a[mid] > x) {// 那要找的值 在左边
            r= mid -1;
        }
        else// 都不是 ,那 a[mid]== x
            return mid;
    }
    return -1;
}
*/

/* x 要找的值, n 离散化后数组的长度 , tmp 离散化存入的数组, 返回x在tmp 中所在的位置 */
int bin(int x,int n,int tmp[] ){
    int l=0,r=n-1;
    while(l <=r){
        int mid = (l+r) >>1;
        if( tmp[mid] == x) return mid;
        if( tmp[mid] < x) // x 在右边
            l= mid+1;
        else // 在左边
            r=mid -1;
    }
    return -1;// 这个值不存在
}


int main(){
    freopen("3.in","r",stdin);
    int m=1;
    int n,i;
    scanf("%d",&n);
    //读取数据
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    //离散化
    //A();
    int k = B();//离散化
    int j = bin(2,k,a);//找到2在a中的对应的值
    
    return 0;
}
