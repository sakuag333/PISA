#include<stdio.h>
#include<iostream>
using namespace std;

long long int mod=1000000007;

long long int pow(long long int a,long long int k)
{
if(k==0)
return 1;
long long int tmp=pow(a,k/2);
tmp=(tmp*tmp)%mod;
if(k%2==1)
tmp=(tmp*a)%mod;
return tmp%mod;
}

long long int inv(long long int p)
{
return (pow(p,mod-2))%mod;
}

long long int f(long long int n)
{
long long int ans=pow(2,n),tmp=1,prev=1;
for(long long int i=1;i<=n/2;i++)
{
//printf("%lld",tmp);
tmp=(tmp+(prev*(((n-i+1)*inv(i))%mod))%mod)%mod;
prev=(prev*(((n-i+1)*inv(i))%mod))%mod;
//cout<<tmp<<endl;
}
//cout<<tmp<<endl;
return (mod+(ans-tmp))%mod;
}

int main()
{
long long int t,n;
int c;
scanf("%lld",&t);
for(int i=0;i<t;i++)
{
scanf("%lld",&n);
for(int i=0;i<n;i++)
scanf("%d",&c);
printf("%lld\n",f(n));
}
return 0;
}
