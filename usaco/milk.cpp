/*
ID: sakuag31
LANG: C++
TASK: milk2
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
int n,t1,t2;
vector<pair<int,int> > v;
FILE *fin  = fopen ("milk2.in", "r");
FILE *fout = fopen ("milk2.out", "w");
fscanf(fin,"%d",&n);
for(int i=0;i<n;i++)
{
fscanf(fin,"%d%d",&t1,&t2);
v.push_back(make_pair(t1,t2));
}
sort(v.begin(),v.end());
int f1=v[0].first,f2=v[0].second,f=f2-f1;
for(int i=1;i<n;i++)
{
if(v[i].first<=f2 && v[i].second<=f2)
continue;
if(v[i].first<=f2 && v[i].second>f2)
f2=v[i].second;
else
{
if(f<f2-f1)
f=f2-f1;
f1=v[i].first;
f2=v[i].second;
}
}
if(f<f2-f1)
f=f2-f1;
int g=0,g2=v[0].second;
for(int i=1;i<n;i++)
{
if(v[i].first<=g2 && v[i].second<=g2)
continue;
if(v[i].first<=g2 && v[i].second>g2)
g2=v[i].second;
else
{
if(g<v[i].first-g2)
g=v[i].first-g2;
g2=v[i].second;
}
}
fprintf(fout,"%d %d\n",f,g);
return 0;
}
