#include<iostream>
#include<map>
#include<vector>
#include<stdio.h>
#include<cmath>
using namespace std;

map<pair<pair<int,int>,pair<int,int> >,bool> mp;
int n,m;
map<pair<int,int>,bool> color;
vector<vector<pair<int,int> > > v(1100); 

inline bool f(int x,int y,int a,int b)
{
double x1=x-a,y1=y-b;
x1*=x1;
y1*=y1;
x1+=y1;
if(sqrt(x1)==(int)x1)
{
//cout<<x<<" "<<y<<" "<<a<<" "<<b<<" "<<sqrt(x1)<<"-- "<<(int)x1<<endl;
return true;
}
return false;
}

void flood(int x,int y,int num)
{
cout<<x<<" "<<y<<endl;
v[num].push_back(make_pair(x,y));
color[make_pair(x,y)]=true;
int tmp=0;
for(int i=0;i<=n;i++)
for(int j=0;j<=m;j++)
if(i+j>0 && !color[make_pair(i,j)] && mp[make_pair(make_pair(x,y),make_pair(i,j))])
flood(i,j,num);
}

int flood_fill()
{
int num=0;
for(int i=0;i<=n;i++)
for(int j=0;j<=m;j++)
if(i+j>0 && !color[make_pair(i,j)])
{
cout<<num<<endl;
flood(i,j,num);
num++;
}
}

int main()
{
cin>>n>>m;
for(int i=0;i<=n;i++)
for(int j=0;j<=m;j++)
for(int k=0;k<=n;k++)
for(int l=0;l<=m;l++)
if(i+j>0 && k+l>0 && !f(i,j,k,l))
{mp[make_pair(make_pair(i,j),make_pair(k,l))]=true;mp[make_pair(make_pair(k,l),make_pair(i,j))]=true;}
flood_fill();
int cnt=-1,comp;
for(int i=0;i<v.size();i++)
if(v[i].size()>cnt)
{cnt=v[i].size();comp=i;}
printf("%d\n",v[comp].size());
for(int i=0;i<v[comp].size();i++)
printf("%d %d\n",v[comp][i].first,v[comp][i].second);
return 0;
}
