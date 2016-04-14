
## 定义

一、Catalan数的定义令h(1)=1，Catalan数满足递归式：h(n) = h(1)*h(n-1) + h(2)*h(n-2) + ... + h(n-1)h(1)，n>=2该递推关系的解为：h(n) = C(2n-2,n-1)/n，n=1,2,3,...（其中C(2n-2,n-1)表示2n-2个中取n-1个的组合数）


问题描述：卡塔兰数，是组合数学中一个常出现在各种计数问题中出现的数列。输入一个整数n，计算h(n)。其递归式如下：h(n)= h(0)*h(n-1)+h(1)*h(n-2) + ... + h(n-1)h(0) (其中n>=2，h(0) = h(1) = 1)    该递推关系的解为：h(n)=C(2n,n)/(n+1) (n=1,2,3,...)


## 代码

```
//函数功能: 计算Catalan的第n项  
//函数参数: n为项数  
//返回值:   第n个Catalan数  
int Catalan(int n)  
{  
    if(n <= 1)  
        return 1;  
  
    int *h = new int [n+1]; //保存临时结果  
    h[0] = h[1] = 1;        //h(0)和h(1)  
    for(int i = 2; i <= n; i++)    //依次计算h(2),h(3)...h(n)  
    {  
        h[i] = 0;  
        for(int j = 0; j < i; j++) //根据递归式计算 h(i)= h(0)*h(i-1)+h(1)*h(i-2) + ... + h(i-1)h(0)  
            h[i] += (h[j] * h[i-1-j]);  
    }  
    int result = h[n]; //保存结果  
    delete [] h;       //注意释放空间  
    return result;  
} 
```

## 引用

 1. http://blog.csdn.net/hackbuteer1/article/details/7450250
 2. http://blog.csdn.net/wuzhekai1985/article/details/6764858
