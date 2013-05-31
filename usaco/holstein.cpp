/*
ID: sakuag31
LANG: C++
TASK: holstein
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
using namespace std;

int v,req[26],g,feed[16][26];
vector<pair<int,string> > ans;

void match(string s)
{
int tmp[v];
for(int j=0;j<v;j++)
tmp[j]=0;
int cnt=0;
for(int i=0;i<s.length();i++)
{
if(s[i]=='1')
{
cnt++;
for(int j=0;j<v;j++)
{
tmp[j]+=feed[g-i-1][j];
}
}
}
for(int j=0;j<v;j++)
{
if(tmp[j]<req[j])
return;
}
ans.push_back(make_pair(cnt,s));
}

void f(int l,string s)
{
if(l==g)
{
match(s);
return;
}
for(int i=0;i<=1;i++)
{
string t=s;
char x='0'+i;
t+=x;
f(l+1,t);
}
}

int main()
{
FILE *fin  = fopen ("holstein.in", "r");
FILE *fout = fopen ("holstein.out", "w");
fscanf(fin,"%d",&v);
for(int i=0;i<v;i++)
fscanf(fin,"%d",&req[i]);
fscanf(fin,"%d",&g);
for(int i=0;i<g;i++)
for(int j=0;j<v;j++)
fscanf(fin,"%d",&feed[i][j]);
string t="";
f(0,t);
sort(ans.begin(),ans.end());
fprintf(fout,"%d ",ans[0].first);
int tmp=0;
for(int i=(ans[0].second).length()-1;i>=0;i--)
{
if((ans[0].second)[i]=='1')
{
tmp++;
fprintf(fout,"%d",g-i);
if(tmp<ans[0].first)
fprintf(fout," ");
}
}
fprintf(fout,"\n");
return 0;
}
