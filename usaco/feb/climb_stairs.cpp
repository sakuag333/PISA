#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

long long int mod=1000000007;

inline int f(long long int k)
{
int ret=0;
while(k>0)
{
ret++;
k=k&(k-1);
}
return ret;
}

int main()
{
int t,n;
long long int g;
vector<long long int> v1,v;
v1.push_back(1);
v1.push_back(1);
for(int i=2;i<=1000000;i++)
v1.push_back((v1[i-2]+v1[i-1])%mod);
for(int i=0;i<=1000000;i++)
v.push_back(f(v1[i]));
scanf("%d",&t);
for(int i=0;i<t;i++)
{
scanf("%d%lld",&n,&g);
if(v[n]==g)
printf("CORRECT\n");
else
printf("INCORRECT\n");
}
return 0;
}
