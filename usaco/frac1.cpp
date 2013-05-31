/*
ID: sakuag31
LANG: C++
TASK: frac1
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
using namespace std;

int gcd(int x,int y)
{
if(y==0)
return x;
return gcd(y,x%y);
}

int main()
{
FILE *fin  = fopen ("frac1.in", "r");
FILE *fout = fopen ("frac1.out", "w");
vector<pair<double,pair<int,int> > > v;
map<pair<int,int>,bool> mp;
int n;
fscanf(fin,"%d",&n);
double num,den;
int div;
for(int i=1;i<=n;i++)
{
for(int j=i+1;j<=n;j++)
{
div=gcd(i,j);
num=i/div;
den=j/div;
if(!mp[make_pair(i/div,j/div)])
{
mp[make_pair(i/div,j/div)]=true;
v.push_back(make_pair(num/den,make_pair(i,j)));
}
}
}
sort(v.begin(),v.end());
fprintf(fout,"0/1\n");
for(int i=0;i<v.size();i++)
fprintf(fout,"%d/%d\n",v[i].second.first,v[i].second.second);
fprintf(fout,"1/1\n");
return 0;
}
