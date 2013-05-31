#include<iostream>
#include<vector>
#include<algorithm>
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

long long int ncr(long long int n,long long int r)
{
long long int tmp=1,prev=1;
for(long long int i=1;i<=r;i++)
{
tmp=(tmp*(((n-i+1)*inv(i))%mod))%mod;
}
return (tmp)%mod;
}

long long int fact(int g)
{
long long int h=g,ret=1;
for(long long int i=h;i>=1;i--)
ret=(ret*i)%mod;
return ret;
}

int main()
{
long long int ans,tmp,c;
long long int n,k,t;
vector<long long int> v;
cin>>t;
for(int i1=0;i1<t;i1++)
{
v.clear();
cin>>n>>k;
c=1;
for(long long int i=0;i<n;i++)
{
cin>>tmp;
v.push_back(tmp);
}
sort(v.begin(),v.end());
ans=0;
long long int prev=1;
for(long long int i=k-1;i<n;i++)
{
ans=(ans+((v[i]%mod)*(prev%mod))%mod)%mod;
prev=((prev%mod)*(((i+1)*inv(i-k+2))%mod))%mod;
}
cout<<"Case #"<<i1+1<<": "<<ans<<endl;
}
return 0;
}
