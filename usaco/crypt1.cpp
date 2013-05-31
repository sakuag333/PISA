/*
ID: sakuag31
LANG: C++
TASK: crypt1
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<iostream>
#include<fstream>
using namespace std;

int cnt=0;
int n;
int a[10];
bool b[10];
vector<int> v;

void h()
{
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
v.push_back(a[i]*10+a[j]);
}
}
}

bool check(int u,int l)
{
int len=0;
while(u>0)
{
len++;
if(!b[u%10])
return false;
u/=10;
}
if(len!=l)
return false;
return true;
}

void g(int l,int num)
{
//cout<<l<<" "<<num<<endl;
if(l==0)
{
//cout<<num<<endl;
for(int i=0;i<v.size();i++)
{
if(check(num*v[i],4) && check(num*(v[i]%10),3) && check(num*(v[i]/10),3))
cnt++;
}
return;
}
for(int i=0;i<n;i++)
g(l-1,a[i]+num*10);
}


int main()
{
FILE *fin  = fopen ("crypt1.in", "r");
FILE *fout = fopen ("crypt1.out", "w");
fscanf(fin,"%d",&n);
for(int i=0;i<=9;i++)
b[i]=false;
for(int i=0;i<n;i++)
{
fscanf(fin,"%d",&a[i]);
b[a[i]]=true;
}
h();
g(3,0);
fprintf(fout,"%d\n",cnt);
return 0;
}
