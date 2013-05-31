/*
ID: sakuag31
LANG: C++
TASK: castle
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int m,n;
int a[51][51];
int g[51][51];
bool color[51][51];
int room;
vector<pair<int,pair<pair<int,int>,char> > > max_area;
vector<int> v(2510);

void f3(int r,int c,bool b[])
{
b[1]=false;
b[2]=false;
b[4]=false;
b[8]=false;
int tmp=a[r][c],tmp1;
while(tmp>0)
{
tmp1=tmp&(tmp-1);
b[tmp-tmp1]=true;
tmp=tmp1;
}
}

void f2(int r,int c,int comp)
{
if(r<=0 || c<=0 || r>n || c>m)
return;
if(color[r][c])
return;
//cout<<r<<" "<<c<<endl;
color[r][c]=true;
g[r][c]=comp;
bool b[9];
f3(r,c,b);
if(!b[1])
f2(r,c-1,comp);
if(!b[2])
f2(r-1,c,comp);
if(!b[4])
f2(r,c+1,comp);
if(!b[8])
f2(r+1,c,comp);
}

int f1()
{
for(int i=1;i<=n;i++)
for(int j=1;j<=m;j++)
color[i][j]=false;
int comp=0;
for(int i=1;i<=n;i++)
{
for(int j=1;j<=m;j++)
{
if(!color[i][j])
{
f2(i,j,comp);
comp++;
}
}
}
room=comp;
return comp;
}

void f6(int r,int c,int comp1,int comp2,char d)
{
//if(r==1 && c==2 && d=='E')
//cout<<comp1<<" "<<comp2<<" "<<v[comp1]<<" "<<v[comp2]<<endl;
max_area.push_back(make_pair(v[comp1]+v[comp2],make_pair(make_pair((-1)*c,r),d)));
}

void f5()
{
bool b[9];
for(int i=1;i<=n;i++)
{
for(int j=1;j<=m;j++)
{
f3(i,j,b);
if(i-1>0 && b[2] && g[i][j]!=g[i-1][j])
f6(i,j,g[i][j],g[i-1][j],'N');
if(j+1<=m && b[4] && g[i][j]!=g[i][j+1])
f6(i,j,g[i][j],g[i][j+1],'E');
}
}
}

int f4()
{
int comp=room;
for(int i=0;i<comp;i++)
v[i]=0;
for(int i=1;i<=n;i++)
for(int j=1;j<=m;j++)
{
//cout<<i<<" "<<j<<" "<<g[i][j]<<endl;
v[g[i][j]]++;
}
int ret=-1;
//for(int i=0;i<comp;i++)
//cout<<i<<" "<<v[i]<<endl;
for(int i=0;i<comp;i++)
if(v[i]>ret)
ret=v[i];
return ret;
}

int main()
{
FILE *fin  = fopen ("castle.in", "r");
FILE *fout = fopen ("castle.out", "w");
fscanf(fin,"%d%d",&m,&n);
for(int i=1;i<=n;i++)
for(int j=1;j<=m;j++)
fscanf(fin,"%d",&a[i][j]);
fprintf(fout,"%d\n",f1());
fprintf(fout,"%d\n",f4());
f5();
sort(max_area.rbegin(),max_area.rend());
fprintf(fout,"%d\n",max_area[0].first);
fprintf(fout,"%d %d %c\n",max_area[0].second.first.second,-1*(max_area[0].second.first.first),max_area[0].second.second);
return 0;
}
