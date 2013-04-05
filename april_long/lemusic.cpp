#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int main()
{
int t,n,b,prev;
long long int l,cnt,ans;
vector<pair<long long int,int> > v;
vector<long long int> w;
bool ck[100001];
scanf("%d",&t);
for(int i1=0;i1<t;i1++)
{
v.clear();
w.clear();
scanf("%d",&n);
for(int i=0;i<n;i++)
{
ck[i]=false;
scanf("%d%lld",&b,&l);
v.push_back(make_pair(b,l));
}
sort(v.begin(),v.end());
cnt=0;
ans=0;
prev=-1;
for(int i=0;i<n;i++)
{
if(v[i].first!=prev)
{w.push_back(v[i].second);prev=v[i].first;ck[i]=true;}
}
sort(w.begin(),w.end());
for(int i=0;i<w.size();i++)
{
cnt++;
ans=ans+cnt*w[i];
}
for(int i=0;i<n;i++)
{
if(!ck[i])
ans=ans+cnt*v[i].second;
}
printf("%lld\n",ans);
}
return 0;
}
