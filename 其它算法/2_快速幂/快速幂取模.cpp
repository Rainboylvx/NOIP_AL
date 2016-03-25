/*-------------------------------------------------
*  Author:Rainboy
*  time: 2016年01月05日 星期二 16时52分31秒
*  © Copyright 2016 Rainboy. All Rights Reserved.
*-------------------------------------------------*/



/*  ===原理
 *
 *       (a * b) % n 
 *   =   ((a % n) * (b % n)) % n
 *   
 *   所以:
 *   
 *       (a^8 * a^4 * a^1) %n
 *   =   (( (a^8 * a^4 ) %n ) * (a^1) % n) %n
 *   =   (( (a^8 %n )* (a^4 % n) ) %n ) * (a^1) % n) %n
 *   
 *       r=1;
 *       while( b & 1)
 *           r *=base % n;
 *       base =base * base % n
 *   
 * */

/* 一句话算法：记住快速幂算法，知道在哪里加入 %n  - r=r*base %n - base =base *base %n */

int pow(int a,int b,int n){
    int r=1,base =a;
    while(b !=0 ){
        if(b & 1)
            r=r * base %n;
        base =base * base;
        b = b >>1;
    }
    return r;
}
