#include<iostream>
#include<vector>
using namespace std;

long long int mod=1000000007;
string s[101];
int n,tmp;

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
long long int tmp=1;
for(long long int i=1;i<=r;i++)
tmp=(tmp*(((n-i+1)*inv(i))%mod))%mod;
return (tmp)%mod;
}

long long int cnt_one(int ind,int blocked)
{
long long int cnt=0;
for(int i=0;i<n;i++)
{
if(i==blocked)
continue;
if(s[i][ind]=='1')
cnt++;
}
return cnt;
}

string to_binary(int k)
{
char x;
string t="";
while(k>0)
{
x='0'+(k%2);
t=x+t;
k/=2;
}
for(int i=t.length();i<=33;i++)
t='0'+t;
return t;
}

int main()
{
cin>>n;
for(int i=0;i<n;i++)
{
cin>>tmp;
s[i]=to_binary(tmp);
}
long long int ans=0,tmp,tmp1,one;
for(int k=0;k<n;k++)
{
tmp1=1;
for(int i=33;i>=0;i--)
{
tmp=0;
one=cnt_one(i,k);
if(one>0)
cout<<k<<" "<<i<<" "<<one<<endl;
for(long long int j=1;j<=one;j+=2)
{
//cout<<ncr(one,one-j)<<endl;
tmp=(tmp+(ncr(one,one-j)%mod))%mod;
}
tmp1=(tmp1*tmp)%mod;
}
ans=(ans+tmp1)%mod;
cout<<tmp1<<" "<<ans<<endl;
}
cout<<(ans%mod)<<endl;
return 0;
}
