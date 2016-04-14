

/* 
 *
 *  v0 =an
 *  vk = vk-1x0+an-k
 *  1<=k<=n
 *  
 * */


/* 正面求的是1.png的公式 */

#include <cstdio>

int main(){
    int v,an,x;
    
    printf("input x:");
    scanf("%d",&x);
    printf("input an:");
    scanf("%d",&an);
    printf("input n:");
    scanf("%d",&n);

    int v= an;
    int k;
    for(k=1;i<=n;k++){
        printf("input a(%d):\n",n-k);
        scanf("%d",&an);
        v=v*x+an;
    }
    printf("%d\n",v);
    return 0;
}
