/*
ID: sakuag31
LANG: C++
TASK: barn1
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
FILE *fin  = fopen ("barn1.in", "r");
FILE *fout = fopen ("barn1.out", "w");
int m,s,c,min1=100000,max1=-1;
int a[201];
vector<pair<int,pair<int,int> > > gap;
fscanf(fin,"%d%d%d",&m,&s,&c);
for(int i=0;i<c;i++)
{
fscanf(fin,"%d",&a[i]);
if(a[i]<min1)
min1=a[i];
if(a[i]>max1)
max1=a[i];
}
if(m==1)
{
fprintf(fout,"%d\n",max1-min1+1);
return 0;
}
sort(a,a+c);
for(int i=1;i<c;i++)
gap.push_back(make_pair(a[i]-a[i-1],make_pair(a[i-1],a[i])));
sort(gap.rbegin(),gap.rend());
int ind=0;
vector<pair<int,int> > v;
while(ind<m-1 && ind<gap.size())
{
v.push_back(make_pair(gap[ind].second.first,gap[ind].second.second));
ind++;
}
sort(v.begin(),v.end());
int prev=min1;
int ans;
int val=10000000;
for(int k=0;k<v.size();k++)
{
ans=0;
prev=min1;
for(int i=0;i<=k;i++)
{
//cout<<v[i].first<<" "<<v[i].second<<endl;
ans=ans+v[i].first-prev+1;
prev=v[i].second;
}
ans=ans+max1-prev+1;
if(ans<val)
val=ans;
}
fprintf(fout,"%d\n",val);
return 0;
}
