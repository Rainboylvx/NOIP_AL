int ex_gcd(int a,int b,int &x,int &y){
    if(b == 0){
        x=1;
        y=0;
        return a;
    }
    int ans = ex_gcd(b,a%b,x,y);
    int tmp =x;
    x = y;
    y = tmp -a/b*y;
    return ans;
}


