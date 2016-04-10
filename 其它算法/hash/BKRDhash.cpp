#include <cstdio>


int ht[1001] = {0};

unsigned int BKRDhash(char *str ){
    unsigned int seed = 131;
    unsigned int hash = 0;
    while(*str){
        hash = hash*seed +( *str++);
    }

    return hash & 0x7fffffff % 1001 ;
}

int main(){
    freopen("1.txt","r",stdin);
    char *tmp[100];
    int n,i;
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        scanf("%s",tmp);
         HT//
    }

    return 0;
}
