/*
ID: sakuag31
LANG: C++
TASK: pprime
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;

bool is_prime[100000];
vector<int> prime,ans;
int a,b;

FILE *fin  = fopen ("pprime.in", "r");
FILE *fout = fopen ("pprime.out", "w");


int get_palin(int x,bool is_odd)
{
int tmp1=x,tmp2=x;
if(is_odd)
tmp1/=10;
while(tmp1>0)
{
tmp2=tmp2*10+(tmp1%10);
tmp1/=10;
}
return tmp2;
}

bool check_prime(int x)
{
if(x<=sqrt(b))
return is_prime[x];
for(int i=0;i<prime.size();i++)
{
if(x%prime[i]==0)
return false;
}
return true;
}

int get_val(int x)
{
int len=0,tmp=x;
while(tmp>0)
{
tmp/=10;
len++;
}
len=(1+len)/2;
tmp=0;
for(int i=0;i<len;i++)
tmp=tmp*10+9;
return tmp;
}

int get_val2(int x)
{
int len=0,tmp=x;
while(tmp>0)
{
tmp/=10;
len++;
}
len=(1+len)/2;
tmp=0;
for(int i=0;i<len;i++)
tmp=tmp*10+1;
return tmp;
}

void pro(int num)
{
//cout<<num<<endl;
if(num%2==0 || num<a || num>b)
return;
if(check_prime(num))
ans.push_back(num);
}

int main()
{
fscanf(fin,"%d%d",&a,&b);
for(int i=1;i<=sqrt(b)+1;i++)
is_prime[i]=true;
is_prime[1]=false;
for(int i=2;i<=sqrt(sqrt(b));i++)
{
if(!is_prime[i])
continue;
for(int j=i;j*i<=sqrt(b);j++)
is_prime[j*i]=false;
}
for(int i=2;i<=sqrt(b);i++)
if(is_prime[i])
prime.push_back(i);
int len;
int lim=get_val(b);
int st=get_val2(a);
int num;
for(int i=st;i<=lim;i++)
{
num=get_palin(i,true);
pro(num);
num=get_palin(i,false);
pro(num);
}
sort(ans.begin(),ans.end());
for(int i=0;i<ans.size();i++)
fprintf(fout,"%d\n",ans[i]);
return 0;
}
