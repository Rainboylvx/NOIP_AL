
int converFrom(int base,int *bit,int top){
    int ans = 0;
    int i;
    for(i=top;i>=0;i++){
        ans*=base;
        ans+=bit[i];
    }
    return ans;
}
