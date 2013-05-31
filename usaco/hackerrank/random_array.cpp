#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

vector<long long int> v;
long long int glo_val;
int glo_st;
int n;

int f(int st,int lim)
{
for(int i=glo_st;i<n;i++)
{
if(glo_val+v[i]>lim)
{
if(i==st)
return -1;
return i-1;
}
glo_val+=v[i];
}
return n-1;
}

int g(int lim)
{
int tmp;
glo_val=0;
glo_st=0;
int cnt=0;
for(int i=0;i<n;i++)
{
tmp=f(i,lim);
if(tmp==-1)
{
glo_st++;
glo_val=0;
}
else
{
cnt+=(tmp-i+1);
glo_st=tmp+1;
glo_val-=v[i];
}
cout<<i<<" "<<glo_st<<" "<<glo_val<<" "<<tmp<<endl;
}
}

int main()
{
long long int t,tmp,val;
scanf("%d%lld",&n,&t);
for(int i=0;i<n;i++)
{
scanf("%lld",&tmp);
v.push_back(tmp);
}
int ans=g(t);
cout<<ans<<endl;
return 0;
}
