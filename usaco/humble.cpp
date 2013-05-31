/*
ID: sakuag31
LANG: C++
TASK: humble
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<set>
#include<queue>
#include<climits>
using namespace std;

int k,n;
long long int  v[101];
priority_queue<pair<unsigned,int> > s;
long long int  min1;
int cnt=0;
long long int lim = 4000000000ll;
pair<unsigned,int> pr;
long long int largest=-1;

long long int f()
{
for(int i=0;i<k;i++)
{
if(v[i]>largest)
largest=v[i];
s.push(make_pair((-1)*v[i],i));
}
while(cnt<n)
{
pr=s.top();
s.pop();
min1=-1*pr.first;
for(int i=pr.second;i<k;i++)
{
if(v[i]*min1<lim && (s.size()<=n || v[i]*min1<largest))
{
s.push(make_pair((-1)*v[i]*min1,i));
if(v[i]*min1>largest)
largest=v[i]*min1;
}
}
cnt++;
}
return min1;
}

int main()
{
FILE *fin  = fopen ("humble.in", "r");
FILE *fout = fopen ("humble.out", "w");
fscanf(fin,"%d%d",&k,&n);
for(int i=0;i<k;i++)
fscanf(fin,"%lld",&v[i]);
long long int ans=f();
fprintf(fout,"%lld\n",ans);
return 0;
}
