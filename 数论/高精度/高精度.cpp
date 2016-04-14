/*============================================================================
* Title : 高精度
* Author: Rainboy
* Time  : 2016-04-14 15:01
* update: 2016-04-14 15:01
* © Copyright 2016 Rainboy. All Rights Reserved.
*=============================================================================*/

const int MAX = 100;

struct hp{
    int num[MAX];

    bool operator > (const hp &) const;
}

bool hp:operator < (const hp &b) const{
    return false;
}

int main(){
    
    return 0;
}
