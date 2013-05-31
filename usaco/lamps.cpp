/*
ID: sakuag31
LANG: C++
TASK: lamps
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
using namespace std;

int n,c;
int a[102];
vector<string> ans;
map<string,bool> mp;

void f(int q,int w,int e,int r)
{
int b[n];
int cnt=0;
for(int i=0;i<n;i++)
b[i]=1;
if(q==1)
{
cnt++;
for(int i=0;i<n;i++)
b[i]=1-b[i];
}
if(w==1)
{
cnt++;
for(int i=0;i<n;i+=2)
b[i]=1-b[i];
}
if(e==1)
{
cnt++;
for(int i=1;i<n;i+=2)
b[i]=1-b[i];
}
if(r==1)
{
cnt++;
for(int i=0;i<n;i+=3)
b[i]=1-b[i];
}
if(cnt>c)
return;
bool ck=true;
for(int i=0;i<n;i++)
{
if(a[i]==-1)
continue;
if(a[i]!=b[i])
{
ck=false;
break;
}
}
if(ck)
{
string s="";
char x;
for(int i=0;i<n;i++)
{
x='0'+b[i];
s+=x;
}
if(!mp[s])
{
ans.push_back(s);
mp[s]=true;
}
}
}

int main()
{
FILE *fin  = fopen ("lamps.in", "r");
FILE *fout = fopen ("lamps.out", "w");
fscanf(fin,"%d",&n);
fscanf(fin,"%d",&c);
int tmp;
for(int i=0;i<n;i++)
a[i]=-1;
while(1)
{
fscanf(fin,"%d",&tmp);
if(tmp==-1)
break;
a[tmp-1]=1;
}
while(1)
{
fscanf(fin,"%d",&tmp);
if(tmp==-1)
break;
a[tmp-1]=0;
}
for(int q=0;q<=1;q++)
for(int w=0;w<=1;w++)
for(int e=0;e<=1;e++)
for(int r=0;r<=1;r++)
f(q,w,e,r);
if(ans.size()==0)
fprintf(fout,"IMPOSSIBLE\n");
else
{
sort(ans.begin(),ans.end());
for(int i=0;i<ans.size();i++)
{
for(int j=0;j<ans[i].length();j++)
fprintf(fout,"%c",ans[i][j]);
fprintf(fout,"\n");
}
}
return 0;
}
