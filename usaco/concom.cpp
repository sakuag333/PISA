/*
ID: sakuag31
LANG: C++
TASK: concom
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
using namespace std;

int mapping[101],fwd[101];
bool is_present[101];
int start=1;
int n;
int com[101][101];
int num;
vector<vector<int> > ans(101);
bool color[101];
int share[101];
vector<int> v;

int h(int x)
{
if(is_present[x])
return fwd[x];
is_present[x]=true;
fwd[x]=start;
mapping[start]=x;
start++;
return fwd[x];
}

void g(int c,vector<int> &v)
{
int curr,cnt;
while(1)
{

for(int i=1;i<=num;i++)
share[i]=0;

for(int i=0;i<v.size();i++)
{
curr=v[i];
for(int i=1;i<=num;i++)
if(com[curr][i]!=-1)
share[i]+=com[curr][i];
}

cnt=0;
for(int i=1;i<=num;i++)
if(!color[i] && share[i]>50)
{color[i]=true;ans[c].push_back(i);v.push_back(i);cnt++;}

if(cnt==0)
break;
//v.clear();
//for(int i=0;i<tmp.size();i++)
//v.push_back(tmp[i]);
}
}

void f(int c)
{
//cout<<c<<endl;
v.clear();
for(int i=1;i<=num;i++)
color[i]=false;
color[c]=true;
for(int i=1;i<=num;i++)
if(!color[i] && com[c][i]>50)
{color[i]=true;v.push_back(i);ans[c].push_back(i);}
v.push_back(c);
g(c,v);
}

int main()
{
FILE *fin  = fopen ("concom.in", "r");
FILE *fout = fopen ("concom.out", "w");
int a,b,p;
fscanf(fin,"%d",&n);
for(int i=1;i<=100;i++)
for(int j=1;j<=100;j++)
com[i][j]=-1;
for(int i=1;i<=100;i++)
is_present[i]=false;
num=-1;
for(int i=0;i<n;i++)
{
fscanf(fin,"%d%d%d",&a,&b,&p);
a=h(a);
b=h(b);
//cout<<a<<" "<<b<<endl;
com[a][b]=p;
}
num=start-1;
for(int i=1;i<=num;i++)
f(i);
vector<vector<int> > y(101);
for(int i=1;i<=num;i++)
{
//sort(ans[i].begin(),ans[i].end());
for(int j=0;j<ans[i].size();j++)
{
y[mapping[i]].push_back(mapping[ans[i][j]]);
//ans[i][j]=mapping[ans[i][j]];
//fprintf(fout,"%d %d\n",mapping[i],mapping[ans[i][j]]);
}
}
for(int i=1;i<=100;i++)
{
if(y[i].size()==0)
continue;
sort(y[i].begin(),y[i].end());
for(int j=0;j<y[i].size();j++)
{
//y[mapping[i]].push_back(mapping[ans[i][j]]);
//ans[i][j]=mapping[ans[i][j]];
fprintf(fout,"%d %d\n",i,y[i][j]);
}
}
return 0;
}
