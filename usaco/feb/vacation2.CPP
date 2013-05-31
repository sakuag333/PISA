#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

long long int ans;

void create(vector<int> &v1,vector<int> &v2,int a,int b,int ind)
{
v1[ind]=a;
v2[ind]=b;
if(a==b)
return;
create(v1,v2,a,(a+b)>>1,(ind<<1)+1);
create(v1,v2,1+((a+b)>>1),b,(ind<<1)+2);
}

void update(vector<int> &v1,vector<int> &v2,vector<long long int> &v3,int a,int b,int ind,int cnt)
{
if(v1[ind]==a && v2[ind]==b)
{
v3[ind]+=cnt;
return;
}
v3[ind]+=cnt;
int mid=(v1[ind]+v2[ind])>>1;
if(b<=mid)
update(v1,v2,v3,a,b,(ind<<1)+1,cnt);
else if(a>mid)
update(v1,v2,v3,a,b,(ind<<1)+2,cnt);
else
{
update(v1,v2,v3,a,mid,(ind<<1)+1,cnt);
update(v1,v2,v3,1+mid,b,(ind<<1)+2,cnt);
}
}

long long int query(vector<int> &v1,vector<int> &v2,vector<long long int> &v3,int a,int b,int ind,int curr)
{
if(a>b)
return 0;
if(v1[ind]==a && v2[ind]==b)
return v3[ind]*(f_min(b,curr)-a+1);
long long int tmp=0;
if(curr==v2[ind])
tmp=v3[ind]*(v2[ind]-v1[ind]+1)
int mid=(v1[ind]+v2[ind])>>1;
if(b<=mid)
return tmp+query(v1,v2,v3,a,b,(ind<<1)+1,curr);
else if(a>mid)
return tmp+query(v1,v2,v3,a,b,(ind<<1)+2,curr);
else
return tmp+query(v1,v2,v3,a,mid,(ind<<1)+1,curr) + query(v1,v2,v3,1+mid,b,(ind<<1)+2,curr);
}

void solve(int node,vector<vector<int> > &v,int curr,vector<int> &v1,vector<int> &v2,vector<long long int> &v3,int arr[],int &len)
{
if(v[node].size()==0)
{
for(int i=0;i<len;i++)
ans+=query(v1,v2,v3,arr[i],arr[i],0,curr);
len=0;
return;
}
for(int i=0;i<v[node].size();i++)
{
if(is_beauty(node))
update(v1,v2,v3,curr,curr,0,1);
else
update(v1,v2,v3,curr,curr,0,-1);
arr[len]=curr;
len++;
solve(v[node][i],v,curr+1,v1,v2,v3,arr,len);
if(is_beauty(node))
update(v1,v2,v3,curr,curr,0,-1);
else
update(v1,v2,v3,curr,curr,0,1);
}
}

int depth(int node,vector<vector<int> > &v)
{
int tmp,d=0;
for(int i=0;i<v[node].size();i++)
{
tmp=1+depth(v[node][i],v);
if(tmp>d)
d=tmp;
}
return d;
}

int main()
{
int n,u,v,root=-1;
scanf("%d",&n);
vector<vector<int> > adj(n);
for(int i=0;i<n;i++)
{
scanf("%d%d",&u,&v);
if(root=-1)
root=u;
adj[u-1].push_back(v-1);
}
int dep=depth(root,adj);
vector<int> seg1(4*dep),seg2(4*dep);
vector<long long int> val(4*dep);
create(seg1,seg2,0,dep,0);
ans=0;
return 0;
}
