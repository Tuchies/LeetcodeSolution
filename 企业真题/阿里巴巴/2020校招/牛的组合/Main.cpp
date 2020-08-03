/*
小强是一个农场主，农场里有n头牛，每头牛有着独一无二的体重，每一头牛的颜色可能跟是m种颜色其中的一种，小强带了一些牛（可能为0个）出来吃草。你需要回答出小强带出来的牛的组合一共有多少种可能？

注意：因为一头牛有自己的体重（没有两头牛体重相等），所以如果四头牛的体重分别是1,2,3,4，颜色分别是y1,y2,y3,y4和另一种方案：四头牛的体重分别是1,2,3,4颜色分别是y1,y3,y2,y4即使两个方案的颜色的种类对应的数量是相同的，但是因为颜色对应的体重不同，所以是两个不同的方案。

由于方案书可能很大，请对1e9+7取模。

输入描述：
两个整数n,m(1≤n,m≤10^9)
输入： 3,2

输出： 27
*/

/**
 * 题目翻译: 无重复元素数组n和m, 求可能的全排列
 * 
 * 也即求 (m+1)^n
 */ 

#include<iostream>
using namespace std;
int mod = 1e9+7;

// 求x的p次方
long long fast_pow(int x,int p){
    if(p==1) return x % mod;
    else {
        // 递归求取
        long long num = fast_pow(x,p/2);
        if(p % 2 == 0)
            return num*num%mod;
        else return num*num*x%mod;
    }
}

int main(){
    int m ,n;
    cin>>n>>m;
    cout<<fast_pow(1+m,n);
    return 0;
}