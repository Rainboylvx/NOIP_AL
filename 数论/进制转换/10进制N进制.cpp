

void conerTo(int num,int base,int *bit,int &top){
    top =-1;
    do{
        bit[++top]   =num %base;
        num/=base;
    }while( num >0);
}
