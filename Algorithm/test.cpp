#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main() {
    int n;
    long long tmp;
    scanf("%d",&n);
    vector<long long> list(n);
    for (int i = 0; i < n; i ++) {
        scanf("%lld",&list[i]);
    }
    return 0;
}

