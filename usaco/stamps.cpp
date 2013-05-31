/*
ID: sakuag31
LANG: C++
TASK: stamps
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<climits>
using namespace std;

int main()
{
FILE *fin  = fopen ("stamps.in", "r");
FILE *fout = fopen ("stamps.out", "w");
int n,k,tmp;
vector<int> v;
fscanf(fin,"%d%d",&n,&k);
vector<int> f;
f.push_back(0);
for(int i=0;i<k;i++)
{
fscanf(fin,"%d",&tmp);
v.push_back(tmp);
}
sort(v.begin(),v.end());
int i=0;
while(1)
{
i++;
tmp=INT_MAX;
for(int p=0;p<v.size();p++)
{
if(v[p]>i)
break;
if(f[i-v[p]]<n && tmp>1+f[i-v[p]])
tmp=1+f[i-v[p]];
}
if(tmp==INT_MAX)
break;
f.push_back(tmp);
}
fprintf(fout,"%d\n",f.size()-1);
return 0;
}
