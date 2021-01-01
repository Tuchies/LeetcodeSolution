#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct ss
{
    int a,b;
};
bool comp(const ss &a,const ss &b)
{
    return a.a < b.a;
}
int main()
{
    vector<ss>v;
    ss s1,s2,s3,s4,s5;
    s1.a=4;s1.b=23;
    s2.a=1;s2.b=213;
    s3.a=2;s3.b=231;
    s4.a=5;s4.b=123;
    s5.a=3;s5.b=223;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    v.push_back(s4);
    v.push_back(s5);
    sort(v.begin(),v.end(),comp);
    int i=0;
    for(i=0;i<5;i++)
    {
        cout<<v[i].a<<" "<<v[i].b<<endl;
    }
    system("pause");
    return 0;
}