/*
ID: sakuag31
LANG: C++
TASK: sprime
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;

bool is_prime[10005];
vector<int> prime;
int n;

FILE *fin  = fopen ("sprime.in", "r");
FILE *fout = fopen ("sprime.out", "w");

bool check_prime(int x)
{
if(x<=10000)
return is_prime[x];
for(int i=0;i<prime.size() && prime[i]<=sqrt(x);i++)
{
if(x%prime[i]==0)
return false;
}
return true;
}

void f(int x,int l)
{
if(l==0)
{
fprintf(fout,"%d\n",x);
return;
}
for(int i=1;i<=9;i++)
{
int y=x*10+i;
if(check_prime(y))
f(y,l-1);
}
}

int main()
{
fscanf(fin,"%d",&n);
for(int i=1;i<=10000;i++)
is_prime[i]=true;
is_prime[1]=false;
for(int i=2;i<=100;i++)
{
if(!is_prime[i])
continue;
for(int j=i;j*i<=10000;j++)
is_prime[j*i]=false;
}
for(int i=2;i<=10000;i++)
if(is_prime[i])
prime.push_back(i);
f(0,n);
return 0;
}
