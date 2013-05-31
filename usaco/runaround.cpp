/*
ID: sakuag31
LANG: C++
TASK: runround
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<climits>
using namespace std;

int m;
int ans;

bool check(int k)
{
int y=k;
string s="";
char x;
while(k>0)
{
x='0'+k%10;
s=x+s;
k/=10;
}
bool a[s.length()];
for(int i=0;i<s.length();i++)
a[i]=false;
int cnt=s.length();
int move,ind=0;
while(cnt>0)
{
move=s[ind]-'0';
//if(y==81362)
//cout<<move<<endl;
while(move>0)
{
if(ind==s.length()-1)
ind=0;
else
ind++;
move--;
}
if(a[ind])
return false;
a[ind]=true;
cnt--;
}
return true;
}

bool f(int l,int k,bool lim[])
{
if(l==0)
{
//if(k>m)
//cout<<k<<endl;
if(k>m && check(k))
{ans=k;return true;}
return false;
}
for(int i=1;i<=9;i++)
{
if(lim[i])
continue;
lim[i]=true;
bool ck=f(l-1,k*10+i,lim);
if(ck)
return true;
lim[i]=false;
}
return false;
}

int get_len(int k)
{
int len=0;
while(k>0)
{
len++;
k/=10;
}
return len;
}

int main()
{
FILE *fin  = fopen ("runround.in", "r");
FILE *fout = fopen ("runround.out", "w");
//cin>>m;
fscanf(fin,"%d",&m);
ans=INT_MAX;
//cout<<ans<<endl;
int l=get_len(m);
//cout<<l<<endl;
bool lim[10];
for(int i=1;i<=9;i++)
lim[i]=false;
f(l,0,lim);
if(ans==INT_MAX)
{
for(int i=1;i<=9;i++)
lim[i]=false;
f(l+1,0,lim);
}
//cout<<ans<<endl;
fprintf(fout,"%d\n",ans);
return 0;
}
