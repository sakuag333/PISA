/*
ID: sakuag31
LANG: C++
TASK: hamming
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<cmath>
using namespace std;

int n,b,d;
int lim;

int g(int x,int y)
{
string s1="",s2="";
char u;
int diff=0;
while(x>0)
{
u='0'+x%2;
s1=s1+u;
x/=2;
}
while(y>0)
{
u='0'+y%2;
s2=s2+u;
y/=2;
}
//cout<<s1<<" "<<s2<<endl;
int ind1=0,ind2=0;
while(ind1<s1.length() && ind2<s2.length())
{
if(s1[ind1]!=s2[ind2])
diff++;
ind1++;
ind2++;
}
while(ind1<s1.length())
{
if(s1[ind1]=='1')
diff++;
ind1++;
}
while(ind2<s2.length())
{
if(s2[ind2]=='1')
diff++;
ind2++;
}
return diff;
}

bool check(int v[],int cnt,int x)
{
int tmp;
for(int i=0;i<cnt;i++)
{
tmp=v[i];
if(g(tmp,x)<d)
return false;
}
return true;
}

bool f(int v[],int cnt)
{
if(cnt==n)
return true;
int st;
if(cnt==0)
st=0;
else
st=1+v[cnt-1];
for(int i=st;i<=lim;i++)
{
if(!check(v,cnt,i))
continue;
//cout<<i<<endl;
v[cnt]=i;
cnt++;
bool ck=f(v,cnt);
if(ck)
return true;
cnt--;
}
return false;
}

int main()
{
FILE *fin  = fopen ("hamming.in", "r");
FILE *fout = fopen ("hamming.out", "w");
fscanf(fin,"%d%d%d",&n,&b,&d);
int v[n];
lim=pow(2,b)-1;
//cout<<g(120,127)<<endl;
//cout<<lim<<endl;
f(v,0);
int tmp=0;
for(int i=0;i<n;i++)
{
tmp++;
fprintf(fout,"%d",v[i]);
if(tmp%10==0 || i==n-1)
fprintf(fout,"\n");
else
fprintf(fout," ");
}
return 0;
}
