/*-------------------------------------------------
*  Author:Rainboy
*  time: 2016-03-28 13:53
*  © Copyright 2016 Rainboy. All Rights Reserved.
*-------------------------------------------------*/


/* 
 *  BKDR hash-->是常用的hash 好用
 *  hash*seed + 下一个 char 
 * */


unsigned int BKDRhash(char *key){
    unsigned int seed = 131;//31 131 1313 13131 etc
    unsigned int hash =0;
    while( *key){
        hash = hash*seed + (*str++);
    }
    return (hash & 0x7fffffff) % Arraylen;
}


/* elfhash-->为了让 字符串 和数值 形成 vlaue->key的关系,根据每个字符串生成独一无二的 数值key
 * 原理: 
 *      1.'a'<<4 +'b'  这样混合
 *      2.int h 来存的话存到第7个字符就会 (h & 0xf0000000) 最高4bit 就会 有值 >0 
 *      3.再存 就会溢出,如果丢失值就会减少一个字符对 hash值的影响
 *      4.所以 把最高8bit和低8bit 异或
 * */


int elfhash(char *key){
    unsigned int hash = 0;
    while(*key){
        hash = (hash<<4) +(*key++);
        unsigned int g = hash & 0xf0000000;
        if(g){
            hash ^= g >>24;
            hash &= ~g;     //高4bit清零
        }

    }

}
