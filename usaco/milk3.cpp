/*
ID: sakuag31
LANG: C++
TASK: milk3
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<set>
using namespace std;

map<pair<int,pair<int,int> >,bool> mp;
map<int,bool> ck;
vector<int> ans;

int cap[3];

void f(int a[3])
{
if(a[0]<0 || a[1]<0 || a[2]<0)
return;
if(mp[make_pair(a[2],make_pair(a[0],a[1]))])
return ;
mp[make_pair(a[2],make_pair(a[0],a[1]))]=true;
//cout<<a<<" "<<b<<" "<<c<<endl;
if(a[0]==0 && !ck[a[2]])
{
//cout<<a<<" "<<b<<" "<<c<<endl;
ans.push_back(a[2]);
ck[a[2]]=true;
}
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
if(i==j)
continue;
int b[3];
b[0]=a[0];
b[1]=a[1];
b[2]=a[2];
if(a[i]<=cap[j]-a[j])
{
b[i]=0;
b[j]=a[j]+a[i];
}
else
{
b[i]=a[i]-(cap[j]-a[j]);
b[j]=cap[j];
}
f(b);
}
}
}
int main()
{
FILE *fin  = fopen ("milk3.in", "r");
FILE *fout = fopen ("milk3.out", "w");
fscanf(fin,"%d%d%d",&cap[0],&cap[1],&cap[2]);
int a[3];
a[0]=0;
a[1]=0;
a[2]=cap[2];
f(a);
sort(ans.begin(),ans.end());
for(int i=0;i<ans.size();i++)
{
fprintf(fout,"%d",ans[i]);
if(i<ans.size()-1)
fprintf(fout," ");
}
fprintf(fout,"\n");
return 0;
}
